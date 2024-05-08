// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "AbilitySystemInterface.h"
#include "AbilitySystemComponent.h"
#include "DreamArena/Interface/RoleAnim.h"
#include "DreamArena/Interface/Impact.h"

#include "BasePlayer.generated.h"


UCLASS(config = Game)
class DREAMARENA_API ABasePlayer : public ACharacter, public IAbilitySystemInterface, public IRoleAnim, public IImpact
{
	GENERATED_BODY()

	//  临时添加一把 到 最后才有

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* RollAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:

	ABasePlayer();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:

	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);


	void RollBegin(const FInputActionValue& Value);


	UFUNCTION(Server, Unreliable)
	void RollBeginOnServer();

	UFUNCTION(NetMulticast, Unreliable)
	void RollBeginOnMulticast();


	void RoleEnd(const FInputActionValue& Value);

	UFUNCTION(Server, Unreliable)
	void RollEndOnServer();

	UFUNCTION(NetMulticast, Unreliable)
	void RollEndOnMulticast();


public:
	void ToRollEnd();

	//添加Ability
	UFUNCTION(BlueprintCallable, Category = "Ability System")
	void GiveAbility(TSubclassOf<UGameplayAbility> Ability, int32 Level = 1);




public:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = GameplayAbilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	UAbilitySystemComponent* GetAbilitySystemComponent()const override;

	// 将在游戏启动时被赋予角色的Abilities数组
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Abilities")
	TArray<TSubclassOf<class UGameplayAbility>> PreloadedAbilities;

protected:

	UPROPERTY(Replicated)
	bool bRolling;


public:

	virtual void GetRoleBaseProperty_Implementation(float& Speed, bool& bWasJump, bool& bIsFalling, bool& WasRoll) override;

	virtual void PlayerAcceptImpact_Implementation() override;


	UFUNCTION(BlueprintCallable)
	void BeBlockHit();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	FTimerHandle PhyTimer;

	virtual void DestroyPlayer();
	
};
