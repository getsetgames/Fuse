//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FuseTypes.generated.h"

UENUM(BlueprintType)
namespace EBPFuseError {
	enum Error
	{
		FUSE_ERROR_NO_ERROR			UMETA(DisplayName="No Error"), /// No error has occurred.
		FUSE_ERROR_NOT_CONNECTED	UMETA(DisplayName="Not Connected"), /// The user is not connected to the internet.
		FUSE_ERROR_REQUEST_FAILED	UMETA(DisplayName="Request Failed"), /// There was an error in establishing a connection with the server.
		FUSE_ERROR_SERVER_ERROR		UMETA(DisplayName="Server Error"), /// The request was processed, but an error occured during processing.
		FUSE_ERROR_BAD_DATA			UMETA(DisplayName="Bad Data"),	/// The server has indicated the data it received was not valid.
		FUSE_ERROR_SESSION_FAILURE	UMETA(DisplayName="Session Failure"), /// The session has recieved an error and the operation did not complete due to this error.
		FUSE_ERROR_INVALID_REQUEST	UMETA(DisplayName="Invalid Request"), /// The request was not valid, and no action will be performed.
		FUSE_ERROR_UNDEFINED		UMETA(DisplayName="Undefined"), /// An Error occured, but there is no information about it
	};
}

UENUM(BlueprintType)
namespace EBPFuseGender {
	enum Gender
	{
		FUSE_GENDER_UNKNOWN	UMETA(DisplayName="Unknown"), /// gender unknown
		FUSE_GENDER_MALE	UMETA(DisplayName="Male"), /// gender male
		FUSE_GENDER_FEMALE	UMETA(DisplayName="Female"), /// gender female
	};
}

USTRUCT()
struct FFuseRewardedObject
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FString PreRollMessage;
	
	UPROPERTY()
	FString RewardMessage;
	
	UPROPERTY()
	FString RewardItem;
	
	UPROPERTY()
	int32 RewardAmount;
	
	FFuseRewardedObject()
	{
		
	}
	
	FORCEINLINE FFuseRewardedObject(FString InPreRollMessage,
									FString InRewardMessage,
									FString InRewardItem,
									int32 InRewardAmount):
	PreRollMessage(InPreRollMessage),
	RewardMessage(InRewardMessage),
	RewardItem(InRewardItem),
	RewardAmount(InRewardAmount)
	{
		
	}
};

USTRUCT()
struct FFuseIAPOfferObject
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FString ProductId;
	
	UPROPERTY()
	float ProductPrice;
	
	UPROPERTY()
	FString ItemName;
	
	UPROPERTY()
	int32 ItemAmount;
	
	FFuseIAPOfferObject()
	{
		
	}
	
	FORCEINLINE FFuseIAPOfferObject(FString InProductId,
									float InProductPrice,
									FString InItemName,
									int32 InItemAmount):
	ProductId(InProductId),
	ProductPrice(InProductPrice),
	ItemName(InItemName),
	ItemAmount(InItemAmount)
	{
		
	}
};

USTRUCT()
struct FFuseVirtualGoodsOfferObject
{
	GENERATED_USTRUCT_BODY()
	
	UPROPERTY()
	FString PurchaseCurrency;
	
	UPROPERTY()
	float PurchasePrice;
	
	UPROPERTY()
	FString ItemName;
	
	UPROPERTY()
	int32 ItemAmount;
	
	FFuseVirtualGoodsOfferObject()
	{
		
	}
	
	FORCEINLINE FFuseVirtualGoodsOfferObject(FString InPurchaseCurrency,
											 float InPurchasePrice,
											 FString InItemName,
											 int32 InItemAmount):
	PurchaseCurrency(InPurchaseCurrency),
	PurchasePrice(InPurchasePrice),
	ItemName(InItemName),
	ItemAmount(InItemAmount)
	{
		
	}
};