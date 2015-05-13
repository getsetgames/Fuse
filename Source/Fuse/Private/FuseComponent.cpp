//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FusePrivatePCH.h"

void UFuseComponent::OnRegister()
{
	Super::OnRegister();
	
	// init here

	UFuseComponent::SessionStartReceivedDelegate.AddUObject(this, &UFuseComponent::SessionStartReceived_Handler);
	UFuseComponent::SessionLoginErrorDelegate.AddUObject(this, &UFuseComponent::SessionLoginError_Handler);
	UFuseComponent::TimeUpdatedDelegate.AddUObject(this, &UFuseComponent::TimeUpdated_Handler);
	UFuseComponent::AccountLoginCompleteDelegate.AddUObject(this, &UFuseComponent::AccountLoginComplete_Handler);
	UFuseComponent::AccountLoginErrorDelegate.AddUObject(this, &UFuseComponent::AccountLoginError_Handler);
	UFuseComponent::NotificationActionDelegate.AddUObject(this, &UFuseComponent::NotificationAction_Handler);
	UFuseComponent::NotificationWillCloseDelegate.AddUObject(this, &UFuseComponent::NotificationWillClose_Handler);
	UFuseComponent::GameConfigurationReceivedDelegate.AddUObject(this, &UFuseComponent::GameConfigurationReceived_Handler);
	UFuseComponent::FriendAddedDelegate.AddUObject(this, &UFuseComponent::FriendAdded_Handler);
	UFuseComponent::FriendRemovedDelegate.AddUObject(this, &UFuseComponent::FriendRemoved_Handler);
	UFuseComponent::FriendAcceptedDelegate.AddUObject(this, &UFuseComponent::FriendAccepted_Handler);
	UFuseComponent::FriendRejectedDelegate.AddUObject(this, &UFuseComponent::FriendRejected_Handler);
	UFuseComponent::FriendsMigratedDelegate.AddUObject(this, &UFuseComponent::FriendsMigrated_Handler);
	UFuseComponent::FriendsListUpdatedDelegate.AddUObject(this, &UFuseComponent::FriendsListUpdated_Handler);
	UFuseComponent::FriendsListErrorDelegate.AddUObject(this, &UFuseComponent::FriendsListError_Handler);
	UFuseComponent::PurchaseVerificationDelegate.AddUObject(this, &UFuseComponent::PurchaseVerification_Handler);
	UFuseComponent::AdAvailabilityResponseDelegate.AddUObject(this, &UFuseComponent::AdAvailabilityResponse_Handler);
	UFuseComponent::RewardedAdCompleteDelegate.AddUObject(this, &UFuseComponent::RewardedAdComplete_Handler);
	UFuseComponent::IAPOfferAcceptedDelegate.AddUObject(this, &UFuseComponent::IAPOfferAccepted_Handler);
	UFuseComponent::VirtualGoodsOfferAcceptedDelegate.AddUObject(this, &UFuseComponent::VirtualGoodsOfferAccepted_Handler);
	UFuseComponent::AdFailedToDisplayDelegate.AddUObject(this, &UFuseComponent::AdFailedToDisplay_Handler);
	UFuseComponent::AdWillCloseDelegate.AddUObject(this, &UFuseComponent::AdWillClose_Handler);
}

void UFuseComponent::OnUnregister()
{
	Super::OnUnregister();
	
	// clean up here
	
	UFuseComponent::SessionStartReceivedDelegate.RemoveAll(this);
	UFuseComponent::SessionLoginErrorDelegate.RemoveAll(this);
	UFuseComponent::TimeUpdatedDelegate.RemoveAll(this);
	UFuseComponent::AccountLoginCompleteDelegate.RemoveAll(this);
	UFuseComponent::AccountLoginErrorDelegate.RemoveAll(this);
	UFuseComponent::NotificationActionDelegate.RemoveAll(this);
	UFuseComponent::NotificationWillCloseDelegate.RemoveAll(this);
	UFuseComponent::GameConfigurationReceivedDelegate.RemoveAll(this);
	UFuseComponent::FriendAddedDelegate.RemoveAll(this);
	UFuseComponent::FriendRemovedDelegate.RemoveAll(this);
	UFuseComponent::FriendAcceptedDelegate.RemoveAll(this);
	UFuseComponent::FriendRejectedDelegate.RemoveAll(this);
	UFuseComponent::FriendsMigratedDelegate.RemoveAll(this);
	UFuseComponent::FriendsListUpdatedDelegate.RemoveAll(this);
	UFuseComponent::FriendsListErrorDelegate.RemoveAll(this);
	UFuseComponent::PurchaseVerificationDelegate.RemoveAll(this);
	UFuseComponent::AdAvailabilityResponseDelegate.RemoveAll(this);
	UFuseComponent::RewardedAdCompleteDelegate.RemoveAll(this);
	UFuseComponent::IAPOfferAcceptedDelegate.RemoveAll(this);
	UFuseComponent::VirtualGoodsOfferAcceptedDelegate.RemoveAll(this);
	UFuseComponent::AdFailedToDisplayDelegate.RemoveAll(this);
	UFuseComponent::AdWillCloseDelegate.RemoveAll(this);
}

UFuseComponent::FFuseDelegate UFuseComponent::SessionStartReceivedDelegate;
UFuseComponent::FFuseErrorDelegate UFuseComponent::SessionLoginErrorDelegate;
UFuseComponent::FFuseIntDelegate UFuseComponent::TimeUpdatedDelegate;
UFuseComponent::FFuseIntStringDelegate UFuseComponent::AccountLoginCompleteDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::AccountLoginErrorDelegate;
UFuseComponent::FFuseStringDelegate UFuseComponent::NotificationActionDelegate;
UFuseComponent::FFuseDelegate UFuseComponent::NotificationWillCloseDelegate;
UFuseComponent::FFuseDelegate UFuseComponent::GameConfigurationReceivedDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::FriendAddedDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::FriendRemovedDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::FriendAcceptedDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::FriendRejectedDelegate;
UFuseComponent::FFuseStringErrorDelegate UFuseComponent::FriendsMigratedDelegate;
UFuseComponent::FFuseDictionaryDelegate UFuseComponent::FriendsListUpdatedDelegate;
UFuseComponent::FFuseErrorDelegate UFuseComponent::FriendsListErrorDelegate;
UFuseComponent::FFuseBoolStringStringDelegate UFuseComponent::PurchaseVerificationDelegate;
UFuseComponent::FFuseBoolErrorDelegate UFuseComponent::AdAvailabilityResponseDelegate;
UFuseComponent::FFuseRewardedObjectDelegate UFuseComponent::RewardedAdCompleteDelegate;
UFuseComponent::FFuseIAPOfferObjectDelegate UFuseComponent::IAPOfferAcceptedDelegate;
UFuseComponent::FFuseVirtualGoodsOfferObjectDelegate UFuseComponent::VirtualGoodsOfferAcceptedDelegate;
UFuseComponent::FFuseDelegate UFuseComponent::AdFailedToDisplayDelegate;
UFuseComponent::FFuseDelegate UFuseComponent::AdWillCloseDelegate;
