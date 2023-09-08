// Fill out your copyright notice in the Description page of Project Settings.


#include "OverheadWidget.h"

#include "Components/TextBlock.h"

void UOverheadWidget::SetDisplayText(FString TextToDisplay)
{
	if (DisplayText)
	{
		DisplayText->SetText(FText::FromString(TextToDisplay));
	}
}

void UOverheadWidget::ShowPlayerNetRole(APawn* InPawn)
{
	ENetRole RemoteRole = InPawn->GetRemoteRole();
	FString Role;
	switch (RemoteRole)
	{
	case ROLE_Authority:
		Role = "Authority";
		break;
	case ROLE_AutonomousProxy:
		Role = "Autonomous Proxy";
		break;
	case ROLE_SimulatedProxy:
		Role = "Simulated Proxy";
		break;
	case ROLE_None:
		Role = "None";
		break;
		default:break;
	}
	FString RemoteRoleString = FString::Printf(TEXT("Remote Role:%s"),*Role);
	SetDisplayText(RemoteRoleString);
}

void UOverheadWidget::NativeDestruct()
{
	RemoveFromParent();
	Super::NativeDestruct();
}
