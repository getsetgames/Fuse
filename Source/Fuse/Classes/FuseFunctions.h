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
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising analytics"), Category = "Fuse")
	static void FuseStartSession(FString AppId);
	
	UFUNCTION(BlueprintPure, meta = (Keywords = "fuse ad advertising analytics"), Category = "Fuse")
	static bool FuseIsAdAvailableForZoneId(FString ZoneId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising analytics"), Category = "Fuse")
	static void FuseShowAdForZoneId(FString ZoneId);
	
	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising analytics"), Category = "Fuse")
	static void FuseShowRewardedAdForZoneId(FString ZoneId, bool ShowPreRoll, bool ShowPostRoll, FString PreRollYesButtonText, FString PreRollNoButtonText, FString PostRollContinueButtonText);

	UFUNCTION(BlueprintCallable, meta = (Keywords = "fuse ad advertising analytics"), Category = "Fuse")
	static void FusePreloadAdForZoneId(FString ZoneId);
};
