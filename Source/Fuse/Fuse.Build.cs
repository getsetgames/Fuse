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

				var CodeDir = Path.Combine(ModulePath,"..","..","lib","iOS","Code");
				//var ExtrasDir = Path.Combine(ModulePath,"..","..","lib","iOS","Extras");

				PrivateIncludePaths.Add(CodeDir);

				PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseSDK.a"));
				PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterAdcolony.a"));
				PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterAppLovin.a"));
				PublicAdditionalLibraries.Add(Path.Combine(CodeDir,"libFuseAdapterHyprMX.a"));

				//PublicAdditionalLibraries.Add(Path.Combine(ExtrasDir,"AdMob","libFuseAdapterAdMob.a"));
				//PublicAdditionalLibraries.Add(Path.Combine(ExtrasDir,"ChartBoost","libFuseAdapterChartBoost.a"));
				//PublicAdditionalLibraries.Add(Path.Combine(ExtrasDir,"Facebook","libFuseAdapterFacebook.a"));
				//PublicAdditionalLibraries.Add(Path.Combine(ExtrasDir,"iAd","libFuseAdapteriAd.a"));
				//PublicAdditionalLibraries.Add(Path.Combine(ExtrasDir,"Millennial","libFuseAdapterMillennial.a"));
			}
		}
	}
}
