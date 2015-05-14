//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FusePrivatePCH.h"

#if PLATFORM_IOS
@interface FuseDelegateImpl : NSObject <FuseDelegate>
@end

static FuseDelegateImpl* FuseDelegateImplSingleton = [[FuseDelegateImpl alloc] init];
#endif

void UFuseFunctions::FuseStartSession(FString AppId)
{
	const UFuseSettings* DefaultSettings = GetDefault<UFuseSettings>();

#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		NSDictionary* options = @{
			kFuseSDKOptionKey_RegisterForPush : @(DefaultSettings->bRegisterForPush),
			kFuseSDKOptionKey_DisableCrashReporting : @(DefaultSettings->bDisableCrashReporting),
		};
		[FuseSDK startSession:AppId.GetNSString() delegate:FuseDelegateImplSingleton withOptions:options];
	});
#endif
}

bool UFuseFunctions::FuseIsAdAvailableForZoneId(FString ZoneId)
{
#if PLATFORM_IOS
	return [FuseSDK isAdAvailableForZoneID:ZoneId.GetNSString()];
#endif
	
	return false;
}

void UFuseFunctions::FuseShowAdForZoneId(FString ZoneId)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[FuseSDK showAdForZoneID:ZoneId.GetNSString() options:nil];
	});
#endif
}

void UFuseFunctions::FusePreloadAdForZoneId(FString ZoneId)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		[FuseSDK preloadAdForZoneID:ZoneId.GetNSString()];
	});
#endif
}

void UFuseFunctions::FuseRegisterInAppPurchase(EInAppPurchaseState::Type PurchaseState, FInAppPurchaseProductInfo PurchaseInfo)
{
#if PLATFORM_IOS
	dispatch_sync(dispatch_get_main_queue(), ^{
		NSData* ReceiptData = [[[NSData alloc] initWithBase64EncodedString:PurchaseInfo.ReceiptData.GetNSString() options:NSDataBase64EncodingEndLineWithLineFeed] autorelease];
		NSInteger TransactionState = PurchaseState == EInAppPurchaseState::Success ? SKPaymentTransactionStatePurchased : SKPaymentTransactionStateFailed;
		NSString* CurrencyCode = [[NSLocale currentLocale] objectForKey:NSLocaleCurrencyCode];
		NSString* CurrencySymbol = [[NSLocale currentLocale] objectForKey:NSLocaleCurrencySymbol];
		NSString* Price = [PurchaseInfo.DisplayPrice.GetNSString() stringByReplacingOccurrencesOfString:CurrencySymbol withString:@""];
		
		//UE_LOG(LogFuse, Log, TEXT("ReceiptData: %s, Purchase State: %i, Price: %s, Currency Code: %s, Purchase Identifier: %s, Transaction Identifier: %s"), *PurchaseInfo.ReceiptData, TransactionState, *FString(Price), *FString(CurrencyCode), *PurchaseInfo.Identifier, *PurchaseInfo.TransactionIdentifier);

		[FuseSDK registerInAppPurchase:ReceiptData
							   TxState:TransactionState
								 Price:Price
							  Currency:CurrencyCode
							 ProductID:PurchaseInfo.Identifier.GetNSString()
						 TransactionID:PurchaseInfo.TransactionIdentifier.GetNSString()];
	});
#endif
}

#if PLATFORM_IOS
@implementation FuseDelegateImpl

-(void) sessionStartReceived
{
	UFuseComponent::SessionStartReceivedDelegate.Broadcast();
}

-(void) sessionLoginError:(NSError*)_error
{
	UFuseComponent::SessionLoginErrorDelegate.Broadcast((EBPFuseError::Error)[_error code]);
}

-(void) timeUpdated:(NSNumber*)_utcTimeStamp
{
	UFuseComponent::TimeUpdatedDelegate.Broadcast([_utcTimeStamp intValue]);
}

-(void) accountLoginComplete:(NSNumber*)_type Account:(NSString*)_account_id
{
	UFuseComponent::AccountLoginCompleteDelegate.Broadcast([_type intValue],FString(_account_id));
}

-(void) account:(NSString*)_account_id  loginError:(NSError*)_error
{
	UFuseComponent::AccountLoginErrorDelegate.Broadcast(FString(_account_id),(EBPFuseError::Error)[_error code]);
}

-(void) notificationAction:(NSString*)_action
{
	UFuseComponent::NotificationActionDelegate.Broadcast(FString(_action));
}

-(void) notficationWillClose
{
	UFuseComponent::NotificationWillCloseDelegate.Broadcast();
}

-(void) gameConfigurationReceived
{
	UFuseComponent::GameConfigurationReceivedDelegate.Broadcast();
}

-(void) friendAdded:(NSString*)_fuse_id Error:(NSError*)_error
{
	UFuseComponent::FriendAddedDelegate.Broadcast(FString(_fuse_id),(EBPFuseError::Error)[_error code]);
}

-(void) friendRemoved:(NSString*)_fuse_id Error:(NSError*)_error
{
	UFuseComponent::FriendRemovedDelegate.Broadcast(FString(_fuse_id),(EBPFuseError::Error)[_error code]);
}

-(void) friendAccepted:(NSString*)_fuse_id Error:(NSError*)_error
{
	UFuseComponent::FriendAcceptedDelegate.Broadcast(FString(_fuse_id),(EBPFuseError::Error)[_error code]);
}

-(void) friendRejected:(NSString*)_fuse_id Error:(NSError*)_error
{
	UFuseComponent::FriendRejectedDelegate.Broadcast(FString(_fuse_id),(EBPFuseError::Error)[_error code]);
}

-(void) friendsMigrated:(NSString*)_fuse_id Error:(NSError*)_error
{
	UFuseComponent::FriendsMigratedDelegate.Broadcast(FString(_fuse_id),(EBPFuseError::Error)[_error code]);
}

-(void) friendsListUpdated:(NSDictionary*)_friendsList
{
	
}

-(void) friendsListError:(NSError*)_error
{
	UFuseComponent::FriendsListErrorDelegate.Broadcast((EBPFuseError::Error)[_error code]);
}

-(void) purchaseVerification:(NSNumber*)_verified TransactionID:(NSString*)_tx_id OriginalTransactionID:(NSString*)_o_tx_id
{
	UFuseComponent::PurchaseVerificationDelegate.Broadcast([_verified boolValue],FString(_tx_id),FString(_o_tx_id));
}

-(void) adAvailabilityResponse:(NSNumber*)_available Error:(NSError*)_error
{
	UFuseComponent::AdAvailabilityResponseDelegate.Broadcast([_available boolValue],(EBPFuseError::Error)[_error code]);
}

-(void) rewardedAdCompleteWithObject:(FuseRewardedObject*) _reward
{
	UFuseComponent::RewardedAdCompleteDelegate.Broadcast(FFuseRewardedObject(FString(_reward.preRollMessage), FString(_reward.rewardMessage), FString(_reward.rewardItem), [_reward.rewardAmount intValue]));
}

-(void) IAPOfferAcceptedWithObject:(FuseIAPOfferObject*) _offer
{
	UFuseComponent::IAPOfferAcceptedDelegate.Broadcast(FFuseIAPOfferObject(FString(_offer.productID), [_offer.productPrice floatValue], FString(_offer.itemName), [_offer.itemAmount intValue]));
}

-(void) virtualGoodsOfferAcceptedWithObject:(FuseVirtualGoodsOfferObject*) _offer
{
	UFuseComponent::VirtualGoodsOfferAcceptedDelegate.Broadcast(FFuseVirtualGoodsOfferObject(FString(_offer.purchaseCurrency), [_offer.purchasePrice floatValue], FString(_offer.itemName), [_offer.itemAmount intValue]));
}

-(void) adFailedToDisplay
{
	UFuseComponent::AdFailedToDisplayDelegate.Broadcast();
}

-(void) adWillClose
{
	UFuseComponent::AdWillCloseDelegate.Broadcast();
}
@end
#endif