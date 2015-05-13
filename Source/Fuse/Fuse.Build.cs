//
//  Created by Derek van Vliet on 2014-12-10.
//  Copyright (c) 2015 Get Set Games Inc. All rights reserved.
//

using System.IO;

namespace UnrealBuildTool.Rules
{
	public class Fuse : ModuleRules
	{
		private string ModulePath
		{
			get { return Path.GetDirectoryName( RulesCompiler.GetModuleFilename( this.GetType().Name ) ); }
		}

		public Fuse(TargetInfo Target)
		{
			PublicIncludePaths.AddRange(
				new string[] {
					// ... add public include paths required here ...
				}
				);

			PrivateIncludePaths.AddRange(
				new string[] {
					"Developer/Fuse/Private",
					// ... add other private include paths required here ...
				}
				);

			PublicDependencyModuleNames.AddRange(
				new string[]
				{
					"Core",
					"CoreUObject",
					"Engine"
					// ... add other public dependencies that you statically link with here ...
				}
				);

			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					// ... add private dependencies that you statically link with here ...
				}
				);

			DynamicallyLoadedModuleNames.AddRange(
				new string[]
				{
					// ... add any modules that your module loads dynamically here ...
				}
				);

			PrivateIncludePathModuleNames.AddRange(
				new string[]
				{
					"Settings"
				}
				);

			if (Target.Platform == UnrealTargetPlatform.IOS) {
				ConfigCacheIni Ini = new ConfigCacheIni(UnrealTargetPlatform.IOS, "Engine", UnrealBuildTool.GetUProjectPath());
				
				bool bIncludeAdColony = false;
				bool bIncludeAppLovin = false;
				bool bIncludeHyprMX = false;
				bool bIncludeAdMob = false;
				bool bIncludeChartboost = false;
				bool bIncludeFacebook = false;
				bool bIncludeiAd = false;
				bool bIncludeMillennial = false;

				string SettingsPath = "/Script/Fuse.FuseSettings";
				Ini.GetBool(SettingsPath, "bIncludeAdColony", out bIncludeAdColony);
				Ini.GetBool(SettingsPath, "bIncludeAppLovin", out bIncludeAppLovin);
				Ini.GetBool(SettingsPath, "bIncludeHyprMX", out bIncludeHyprMX);
				Ini.GetBool(SettingsPath, "bIncludeAdMob", out bIncludeAdMob);
				Ini.GetBool(SettingsPath, "bIncludeChartboost", out bIncludeChartboost);
				Ini.GetBool(SettingsPath, "bIncludeFacebook", out bIncludeFacebook);
				Ini.GetBool(SettingsPath, "bIncludeiAd", out bIncludeiAd);
				Ini.GetBool(SettingsPath, "bIncludeMillennial", out bIncludeMillennial);
				
				PublicFrameworks.AddRange(
					new string[]
					{
						"Accelerate",
						"AdSupport",
						"AudioToolbox",
						"AVFoundation",
						"CoreGraphics",
						"CoreLocation",
						"CoreMedia",
						"CoreTelephony",
						"EventKit",
						"EventKitUI",
						"Foundation",
						"GameKit",
						"MediaPlayer",
						"MessageUI",
						"MobileCoreServices",
						"QuartzCore",
						"Social",
						"StoreKit",
						"SystemConfiguration",
						"Twitter",
						"UIKit"
					}
				);

				PublicAdditionalLibraries.Add("sqlite3");
				PublicAdditionalLibraries.Add("xml2");
				PublicAdditionalLibraries.Add("z");

				var CodeDir = Path.Combine(ModulePath,"..","..","lib","FuseSDKiOS","Code");

				PrivateIncludePaths.Add(CodeDir);

				PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseSDK.a"));
				
				// optional adapters
				if (bIncludeAdColony)
				{
					PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterAdcolony.a"));
				}
				
				if (bIncludeAppLovin)
				{
					PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterAppLovin.a"));
				}
				
				if (bIncludeHyprMX)
				{
					PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterHyprMX.a"));
				}
				
				var FuseExtrasDir = Path.Combine(ModulePath,"..","..","lib","FuseSDKiOS","Extras");
				var ExtrasiOSDir = "../../lib/Extras/iOS";
				
				if (bIncludeAdMob)
				{
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"AdMob","libFuseAdapterAdMob.a"));
					PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"GoogleMobileAds",
							ExtrasiOSDir + "/AdMob/GoogleMobileAds.embeddedframework.zip"
						)
					);
				}
				
				if (bIncludeChartboost)
				{
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"ChartBoost","libFuseAdapterChartBoost.a"));
					PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"Chartboost",
							ExtrasiOSDir + "/Chartboost/Chartboost.embeddedframework.zip"
						)
					);
				}
				
				if (bIncludeFacebook)
				{
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"Facebook","libFuseAdapterFacebook.a"));
					PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"FBAudienceNetwork",
							ExtrasiOSDir + "/Facebook/FBAudienceNetwork.embeddedframework.zip"
						)
					);
				}
				
				if (bIncludeiAd)
				{
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"iAd","libFuseAdapteriAd.a"));
				}
				
				if (bIncludeMillennial)
				{
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"Millennial","libFuseAdapterMillennial.a"));
					PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"MillennialMedia",
							ExtrasiOSDir + "/Millennial/MillennialMedia.embeddedframework.zip"
						)
					);
					PublicAdditionalLibraries.Add(Path.Combine(FuseExtrasDir,"AdMob","libFuseAdapterAdMob.a"));
					PublicAdditionalFrameworks.Add(
						new UEBuildFramework(
							"SpeechKit",
							ExtrasiOSDir + "/Millennial/SpeechKit.embeddedframework.zip"
						)
					);
				}
				
			}
		}
	}
}
