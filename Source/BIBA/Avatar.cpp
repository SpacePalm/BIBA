// Fill out your copyright notice in the Description page of Project Settings.


#include "Avatar.h"


// Sets default values
 AAvatar::AAvatar()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input

void AAvatar::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AAvatar::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AAvatar::MoveRight);
 	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AAvatar::Yaw);
 	PlayerInputComponent->BindAxis(TEXT("Pitch"), this, &AAvatar::Pitch);

 	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Pressed, this, &AAvatar::Jump);
 	PlayerInputComponent->BindAction(TEXT("Jump"),IE_Released, this, &AAvatar::StopJumping);
}

void AAvatar::MoveForward(float Value) {
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Value);

}
void AAvatar::MoveRight(float Value) {
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Value);
}
void AAvatar::Yaw(float Value)
 {
	 AddControllerYawInput( 200.f *Value * GetWorld() -> GetDeltaSeconds());
 }
void AAvatar::Pitch(float Value)
 {
 	AddControllerPitchInput( 200.f *Value * GetWorld() -> GetDeltaSeconds());
 }
