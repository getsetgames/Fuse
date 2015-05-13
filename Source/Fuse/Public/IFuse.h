//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#pragma once

#include "ModuleManager.h"

class IFuse : public IModuleInterface
{

public:

	static inline IFuse& Get()
	{
		return FModuleManager::LoadModuleChecked< IFuse >( "Fuse" );
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded( "Fuse" );
	}
};

