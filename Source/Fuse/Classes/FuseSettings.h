//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "FuseSettings.generated.h"

UCLASS(config = Engine, defaultconfig)
class UFuseSettings : public UObject
{
	GENERATED_BODY()
	
public:
	UFuseSettings(const FObjectInitializer& ObjectInitializer);
	
	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include AdColony"))
	bool bIncludeAdColony;
	
	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include AppLovin"))
	bool bIncludeAppLovin;

	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include HyprMX"))
	bool bIncludeHyprMX;

	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include AdMob"))
	bool bIncludeAdMob;
	
	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include Chartboost"))
	bool bIncludeChartboost;
	
	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include Facebook"))
	bool bIncludeFacebook;

	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include iAd"))
	bool bIncludeiAd;

	UPROPERTY(Config, EditAnywhere, Category=Adapters, meta=(DisplayName="Include Millennial"))
	bool bIncludeMillennial;
	
	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Register for Push on Session Start"))
	bool bRegisterForPush;

	UPROPERTY(Config, EditAnywhere, Category=General, meta=(DisplayName="Disable Crash Reporting"))
	bool bDisableCrashReporting;
};
