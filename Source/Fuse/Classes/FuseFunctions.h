//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FuseFunctions.generated.h"

UCLASS(NotBlueprintable)
class UFuseFunctions : public UObject
{
	GENERATED_BODY()
	
public:	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising"), Category = "Fuse")
	static void FuseStartSession(FString AppId);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "fuse ad advertising"), Category = "Fuse")
	static bool FuseIsAdAvailableForZoneId(FString ZoneId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising"), Category = "Fuse")
	static void FuseShowAdForZoneId(FString ZoneId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising"), Category = "Fuse")
	static void FusePreloadAdForZoneId(FString ZoneId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse purchase"), Category = "Fuse")
	static void FuseRegisterInAppPurchase(EInAppPurchaseState::Type PurchaseState, FInAppPurchaseProductInfo PurchaseInfo);
};
