//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FusePrivatePCH.h"
#include "FuseSettings.h"

UFuseSettings::UFuseSettings(const FObjectInitializer& ObjectInitializer)
: Super(ObjectInitializer)
, bIncludeAdColony(true)
, bIncludeAppLovin(true)
, bIncludeHyprMX(true)
, bIncludeAdMob(false)
, bIncludeChartboost(false)
, bIncludeFacebook(false)
, bIncludeiAd(false)
, bIncludeMillennial(false)
, bRegisterForPush(true)
, bDisableCrashReporting(false)
{
	
}
