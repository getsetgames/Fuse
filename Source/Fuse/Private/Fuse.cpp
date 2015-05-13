//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

#include "FusePrivatePCH.h"
#include "FuseSettings.h"
#include "ISettingsModule.h"

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
	// register settings
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "Fuse",
										 LOCTEXT("RuntimeSettingsName", "Fuse"),
										 LOCTEXT("RuntimeSettingsDescription", "Configure the Fuse plugin"),
										 GetMutableDefault<UFuseSettings>()
										 );
	}
}


void FFuse::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
