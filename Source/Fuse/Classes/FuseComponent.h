//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FuseTypes.h"
#include "FuseComponent.generated.h"

UCLASS(ClassGroup=Fuse, HideCategories=(Activation, "Components|Activation", Collision), meta=(BlueprintSpawnableComponent))
class UFuseComponent : public UActorComponent
{
	GENERATED_BODY()
	
public:
	// static delegates
	
	DECLARE_MULTICAST_DELEGATE(FFuseDelegate);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseErrorDelegate, EBPFuseError::Error);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseStringDelegate, FString);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseIntDelegate, int32);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseIntStringDelegate, int32, FString);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseStringStringDelegate, FString, FString);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseStringErrorDelegate, FString, EBPFuseError::Error);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseDictionaryDelegate, TArray<FString>, TArray<FString>);
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FFuseStringStringStringDelegate, FString, FString, FString);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseBoolStringDelegate, bool, FString);
	DECLARE_MULTICAST_DELEGATE_TwoParams(FFuseBoolErrorDelegate, bool, EBPFuseError::Error);
	DECLARE_MULTICAST_DELEGATE_ThreeParams(FFuseBoolStringStringDelegate, bool, FString, FString);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseRewardedObjectDelegate, FFuseRewardedObject);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseIAPOfferObjectDelegate, FFuseIAPOfferObject);
	DECLARE_MULTICAST_DELEGATE_OneParam(FFuseVirtualGoodsOfferObjectDelegate, FFuseVirtualGoodsOfferObject);
	
	static FFuseDelegate SessionStartReceivedDelegate;
	static FFuseErrorDelegate SessionLoginErrorDelegate;
	static FFuseIntDelegate TimeUpdatedDelegate;
	static FFuseIntStringDelegate AccountLoginCompleteDelegate;
	static FFuseStringErrorDelegate AccountLoginErrorDelegate;
	static FFuseStringDelegate NotificationActionDelegate;
	static FFuseDelegate NotificationWillCloseDelegate;
	static FFuseDelegate GameConfigurationReceivedDelegate;
	static FFuseStringErrorDelegate FriendAddedDelegate;
	static FFuseStringErrorDelegate FriendRemovedDelegate;
	static FFuseStringErrorDelegate FriendAcceptedDelegate;
	static FFuseStringErrorDelegate FriendRejectedDelegate;
	static FFuseStringErrorDelegate FriendsMigratedDelegate;
	static FFuseDictionaryDelegate FriendsListUpdatedDelegate;
	static FFuseErrorDelegate FriendsListErrorDelegate;
	static FFuseBoolStringStringDelegate PurchaseVerificationDelegate;
	static FFuseBoolErrorDelegate AdAvailabilityResponseDelegate;
	static FFuseRewardedObjectDelegate RewardedAdCompleteDelegate;
	static FFuseIAPOfferObjectDelegate IAPOfferAcceptedDelegate;
	static FFuseVirtualGoodsOfferObjectDelegate VirtualGoodsOfferAcceptedDelegate;
	static FFuseDelegate AdFailedToDisplayDelegate;
	static FFuseDelegate AdWillCloseDelegate;
	
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFuseDynDelegate);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseErrorDynDelegate, EBPFuseError::Error, Error);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseTimeUpdatedDynDelegate, int32, UTCTimeStamp);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuseAccountLoginCompleteDynDelegate, int32, Type, FString, AccountId);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuseAccountLoginErrorDynDelegate, FString, AccountId, EBPFuseError::Error, Error);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseNotificationActionDynDelegate, FString, Action);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuseFriendActionDynDelegate, FString, FuseId, EBPFuseError::Error, Error);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuseFriendsListUpdatedDynDelegate, TArray<FString>, Keys, TArray<FString>, Values);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FFusePurchaseVerificationDynDelegate, bool, Verified, FString, TransactionId, FString, OriginalTransactionId);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFuseAdAvailabilityResponseDynDelegate, bool, Available, EBPFuseError::Error, Error);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseRewardedAdCompleteDynDelegate, FFuseRewardedObject, Reward);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseIAPOfferAcceptedDynDelegate, FFuseIAPOfferObject, Offer);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFuseVirtualGoodsOfferObjectDynDelegate, FFuseVirtualGoodsOfferObject, Offer);
	
	// blueprint assignables

	UPROPERTY(BlueprintAssignable)
	FFuseDynDelegate SessionStartReceived;
	
	UPROPERTY(BlueprintAssignable)
	FFuseErrorDynDelegate SessionLoginError;

	UPROPERTY(BlueprintAssignable)
	FFuseTimeUpdatedDynDelegate TimeUpdated;
	
	UPROPERTY(BlueprintAssignable)
	FFuseAccountLoginCompleteDynDelegate AccountLoginComplete;
	
	UPROPERTY(BlueprintAssignable)
	FFuseAccountLoginErrorDynDelegate AccountLoginError;
	
	UPROPERTY(BlueprintAssignable)
	FFuseNotificationActionDynDelegate NotificationAction;
	
	UPROPERTY(BlueprintAssignable)
	FFuseDynDelegate NotificationWillClose;
	
	UPROPERTY(BlueprintAssignable)
	FFuseDynDelegate GameConfigurationReceived;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendActionDynDelegate FriendAdded;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendActionDynDelegate FriendRemoved;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendActionDynDelegate FriendAccepted;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendActionDynDelegate FriendRejected;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendActionDynDelegate FriendsMigrated;
	
	UPROPERTY(BlueprintAssignable)
	FFuseFriendsListUpdatedDynDelegate FriendsListUpdated;
	
	UPROPERTY(BlueprintAssignable)
	FFuseErrorDynDelegate FriendsListError;
	
	UPROPERTY(BlueprintAssignable)
	FFusePurchaseVerificationDynDelegate PurchaseVerification;
	
	UPROPERTY(BlueprintAssignable)
	FFuseAdAvailabilityResponseDynDelegate AdAvailabilityResponse;
	
	UPROPERTY(BlueprintAssignable)
	FFuseRewardedAdCompleteDynDelegate RewardedAdComplete;
	
	UPROPERTY(BlueprintAssignable)
	FFuseIAPOfferAcceptedDynDelegate IAPOfferAccepted;
	
	UPROPERTY(BlueprintAssignable)
	FFuseVirtualGoodsOfferObjectDynDelegate VirtualGoodsOfferAccepted;
	
	UPROPERTY(BlueprintAssignable)
	FFuseDynDelegate AdFailedToDisplay;
	
	UPROPERTY(BlueprintAssignable)
	FFuseDynDelegate AdWillClose;
	
	void OnRegister() override;
	void OnUnregister() override;
private:
	// handlers
	
	void SessionStartReceived_Handler() { SessionStartReceived.Broadcast(); }
	void SessionLoginError_Handler(EBPFuseError::Error Error) { SessionLoginError.Broadcast(Error); }
	void TimeUpdated_Handler(int32 UTCTimeStamp) { TimeUpdated.Broadcast(UTCTimeStamp); }
	void AccountLoginComplete_Handler(int32 Type, FString AccountId) { AccountLoginComplete.Broadcast(Type, AccountId); }
	void AccountLoginError_Handler(FString AccountId, EBPFuseError::Error Error) { AccountLoginError.Broadcast(AccountId, Error); }
	void NotificationAction_Handler(FString Action) { NotificationAction.Broadcast(Action); }
	void NotificationWillClose_Handler() { NotificationWillClose.Broadcast(); }
	void GameConfigurationReceived_Handler() { GameConfigurationReceived.Broadcast(); }
	void FriendAdded_Handler(FString FuseId, EBPFuseError::Error Error) { FriendAdded.Broadcast(FuseId, Error); }
	void FriendRemoved_Handler(FString FuseId, EBPFuseError::Error Error) { FriendRemoved.Broadcast(FuseId, Error); }
	void FriendAccepted_Handler(FString FuseId, EBPFuseError::Error Error) { FriendAccepted.Broadcast(FuseId, Error); }
	void FriendRejected_Handler(FString FuseId, EBPFuseError::Error Error) { FriendRejected.Broadcast(FuseId, Error); }
	void FriendsMigrated_Handler(FString FuseId, EBPFuseError::Error Error) { FriendsMigrated.Broadcast(FuseId, Error); }
	void FriendsListUpdated_Handler(TArray<FString> Keys, TArray<FString> Values) { FriendsListUpdated.Broadcast(Keys, Values); }
	void FriendsListError_Handler(EBPFuseError::Error Error) { FriendsListError.Broadcast(Error); }
	void PurchaseVerification_Handler(bool Verified, FString TransactionId, FString OriginalTransactionId) { PurchaseVerification.Broadcast(Verified, TransactionId, OriginalTransactionId); }
	void AdAvailabilityResponse_Handler(bool Available, EBPFuseError::Error Error) { AdAvailabilityResponse.Broadcast(Available, Error); }
	void RewardedAdComplete_Handler(FFuseRewardedObject RewardedObject) { RewardedAdComplete.Broadcast(RewardedObject); }
	void IAPOfferAccepted_Handler(FFuseIAPOfferObject IAPOfferObject) { IAPOfferAccepted.Broadcast(IAPOfferObject); }
	void VirtualGoodsOfferAccepted_Handler(FFuseVirtualGoodsOfferObject VirtualGoodsOfferObject) { VirtualGoodsOfferAccepted.Broadcast(VirtualGoodsOfferObject); }
	void AdFailedToDisplay_Handler() { AdFailedToDisplay.Broadcast(); }
	void AdWillClose_Handler() { AdWillClose.Broadcast(); }
};
