// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"


UENUM()
enum class ERoleType : uint8 {
	DoubleSword

};


UENUM()
enum class ESpinArenaGameStatus : uint8 {
	Ready,
	Gaming,
	GameOver,
};