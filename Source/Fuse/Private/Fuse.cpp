//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FusePrivatePCH.h"

DEFINE_LOG_CATEGORY(LogFuse);

#define LOCTEXT_NAMESPACE "Fuse"

class FFuse : public IFuse
{
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

IMPLEMENT_MODULE( FFuse, Fuse )

void FFuse::StartupModule()
{
}


void FFuse::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
