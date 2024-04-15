// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAnim.h"
#include "../Interface/RoleAnim.h"
#include "Animation/AnimInstance.h"

UBaseAnim::UBaseAnim()
{
	
}



void UBaseAnim::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	check(TryGetPawnOwner());

}

void UBaseAnim::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	
	if (TryGetPawnOwner())
	{
		GetRoleProperty();

	}


}

FORCEINLINE void UBaseAnim::GetRoleProperty()
{
	if (TryGetPawnOwner()->GetClass()->ImplementsInterface(URoleAnim::StaticClass()))
	{
		IRoleAnim* RoleAnim_BPI = CastChecked<IRoleAnim>(TryGetPawnOwner());

		RoleAnim_BPI->Execute_GetRoleBaseProperty(TryGetPawnOwner(), Speed, bWasJump, bFalling);

	}

}
