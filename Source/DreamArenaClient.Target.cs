// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DreamArenaClientTarget : TargetRules
{
    public DreamArenaClientTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Client;
		IncludeOrderVersion = EngineIncludeOrderVersion.Latest;
		BuildEnvironment = TargetBuildEnvironment.Shared;
		ExtraModuleNames.Add("DreamArena");
	}
}
