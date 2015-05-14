//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "CoreUObject.h"
#include "Engine.h"
#include "OnlineStoreInterface.h"

#include "IFuse.h"

// You should place include statements to your module's private header files here.  You only need to
// add includes for headers that are used in most of your module's source files though.

#if PLATFORM_IOS
#import "FuseSDK.h"
#import "FuseSDKDefinitions.h"
#endif

DECLARE_LOG_CATEGORY_EXTERN(LogFuse, Log, All);

#include "FuseClasses.h"
