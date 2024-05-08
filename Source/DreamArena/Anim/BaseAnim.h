// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BaseAnim.generated.h"

class IRoleAnim;

UCLASS()
class DREAMARENA_API UBaseAnim : public UAnimInstance 
{
	GENERATED_BODY()
public:

	UBaseAnim();

public:

	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;




	// 蓝图多线程
//	virtual void NativeThreadSafeUpdateAnimation(float DeltaSeconds);

	FORCEINLINE void GetRoleProperty();


protected:

	UPROPERTY(BlueprintReadOnly,Category = "RoleProperty")
	float Speed;

	UPROPERTY(BlueprintReadOnly, Category = "RoleProperty")
	bool bWasJump;

	UPROPERTY(BlueprintReadOnly, Category = "RoleProperty")
	bool bFalling;

	UPROPERTY(BlueprintReadOnly, Category = "RoleProperty")
	bool bRolling;

	

protected:

	UFUNCTION()
	void AnimNotify_RollEnd(UAnimNotify* Notify);

};
