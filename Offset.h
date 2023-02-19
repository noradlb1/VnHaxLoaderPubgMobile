#pragma once

#include "Includes.h"

namespace Offset
{
	/// <summary>
	const DWORD bDead = 0x9d0;
	const DWORD IsDead = 0x9d0;// 	bool bDead;//(ByteOffset: 0, ByteMask: 1, FieldMask: 1)[Offset: 0x9d0, Size: 0x1]
	const DWORD PersistentLevel = 0x20;// 	Level* PersistentLevel;//[Offset: 0x20, Size: 0x4]
	const DWORD NetDriver = 0x24; // not cheng
	const DWORD ServerConnection = 0x60; // not cheng
	const DWORD PlayerController = 0x20; // not cheng
	const DWORD AcknowledgedPawn = 0x350;// PlayerController.Controller.Actor.Object, Pawn* AcknowledgedPawn;//[Offset:
	const DWORD EntityList = 0x70;// 0x7C; // not cheng
	const DWORD EntityCount = EntityList + 4; ///= 0x74;// = EntityList + 4; // not cheng
	const DWORD gameInstance = 0x24;// not cheng
	const DWORD playerCarry = 0x20;// not cheng
	const DWORD RootComponent = 0x164;// SceneComponent* RootComponent;//[Offset: 0x164, Size: 0x4]
	const DWORD CurrentStates = 0xb18;//2.3 //= 0xb00;//2.2//	uint64 CurrentStates;//[Offset: 0xb10, Size: 0x8]

	//const DWORD FastRun = 0x2280;			//CharacterOverrideAttrs CharacterOverrideAttrs;//[Offset:
	//const DWORD DeadOffset = 0x9e0;			// bool bDead;//(ByteOffset:
	//const DWORD  ofStateInt = 0xb10;		//uint64 CurrentStates;//[Offset:


	// AActor
	const DWORD TeamId = 0x6a4;//up 0x69c;// Class: UAECharacter.Character.Pawn.Actor.Object, int TeamID;//[Offset:
	const DWORD PoseState = 0xfd8;//2.3 //=0xfc0; 2.2//up 0xfb8;// byte PoseState;//[Offset: 0xfb8, Size: 0x1]
	const DWORD IsBot = 0x71c;//up 0x714;// bool bIsAI;//(ByteOffset:
	const DWORD Name = 0x670;//up 0x668;// Class: UAECharacter.Character.Pawn.Actor.Object, FString PlayerName;//[Offset:
	const DWORD Status = 0xb18;//2.3 //= 0xb00;//2.2 //= 0xb10;	// FString PlayerName;//[Offset:
	const DWORD Nation = 0x67c;//2.3//=0x760;//2.2// 0x67c;//UP 0x768; //0x674;// FString Nation;//[Offset: 0x768, Size: 0xc] ////Class: UAEPlayerController.LuaPlayerController.PlayerController.Controller.Actor.Object
	const DWORD Health = 0x9b8;//up 0x9a4;// Class: STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object, float Health;//[Offset: 0x9a4, Size: 0x4]
	const DWORD HealthMax = 0x9bc;//up 0x9a8;// Class: STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object, float HealthMax;//[Offset: 0x9a8, Size: 0x4]
	const DWORD KnockedHealth = 0x1214;// float NearDeathBreath;//[Offset:
	const int weaponOffset = 0x1eb4;//2.3// 0x1e70;//2.2 //= 0x1e50;//0x1e9c;//	STExtraWeapon* CurrentReloadWeapon;//[Offset: 0x1e9c, Size: 0x4]
	const int ShootWeapon = 0x19ac; //= 3532; // not fund no need
	//

	/// <summary>
	/// NEW MASODS FOR AMO TOTAL AND TYPE OF WOPEN

	const DWORD CurrWeapon = 0x1ad8; //= 0x1e50; // https://www.unknowncheats.me/forum/pubg-mobile/506220-pubgm-global-2-1-offsets.html
	const DWORD CurBulletNumInClip = 0xb1c;//2.3// =0xb00;//2.2/// Class: STExtraShootWeapon.STExtraWeapon.LuaActor.Actor.Object, int CurBulletNumInClip;//[Offset:
	const DWORD CurMaxBulletNumInOneClip = 0xb30;//2.3 = 0xb14;//2.2// Class: STExtraShootWeapon.STExtraWeapon.LuaActor.Actor.Object, int CurMaxBulletNumInOneClip;//[Offset: 0xacc, Size: 0x4]
	const DWORD ScopeFov = 0x12ec;//2.3 = 0x12c8;//2.2 //= 0x1200;// Class: STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object, float ScopeFov;//[Offset: 0x130c, Size: 0x4]
	const DWORD gNames = 0; // gameloop

	// Lot BOX 
	const DWORD deadbox = 0x690;  // PickUpItemData[] PickUpDataList;//[Offset:
	const DWORD itemBase = 0x690;  // PickUpItemData[] PickUpDataList;//[Offset:
	const DWORD boxItemsCount = 0x69c; // not fund need
	/// New Drow Air Drop
	const DWORD PickUpDataList = 0x690; //= 0x684; /// Class: PickUpListWrapperActor.PickUpWrapperActor.UAENetActor.LuaActor.Actor.Object PickUpItemData[] PickUpDataList;//[Offset: 0x690, Size: 0xc]

	const DWORD CharacterMovement = 0x344;// 0x344;//up 0x348; //= 0x114;// Class: Character.Pawn.Actor.Object, CharacterMovementComponent* CharacterMovement;//[Offset:
	const DWORD LastUpdateVelocity = 0x250;	// Vector LastUpdateVelocity;//[Offset:
	const DWORD Velocity = 0xc8;			// Vector Velocity;//[Offset:

	const DWORD RelativeLocation = 0x118;	// Class: SceneComponent.ActorComponent.Object, Vector RelativeLocation;//[Offset: 0x118, Size: 0xc]
	const DWORD RelativeRotation = 0x124;	// Class: SceneComponent.ActorComponent.Object, Rotator RelativeRotation;//[Offset: 0x124, Size: 0xc]
	const DWORD Position = 0x150; // not Cheng
	const DWORD IsVisible = 0x1bc;// Class: SceneComponent.ActorComponent.Object, bVisible // check : 0x27e/ 0x1bc

	// Bone
	const DWORD Mesh = 0x340;//UP 0x344;// Class: Character.Pawn.Actor.Object, SkeletalMeshComponent* Mesh;//[Offset: 0x344, Size: 0x4]
	const DWORD BodyAddv = 0x140;// 0x140; // Class: WeaponMeshCfg, enum meshType;//[Offset:
	const DWORD MinLOD = 0x5e8;//up 0x5e8; // Class: StaticMeshComponent.MeshComponent.PrimitiveComponent.SceneComponent.ActorComponent.Object, int MinLOD;//[Offset: 0x5b0,  / boneOffset

	// Camera
	const DWORD PlayerCameraManager = 0x360;//up 0x368;// Class: PlayerController.Controller.Actor.Object, PlayerCameraManager* PlayerCameraManager;//[Offset: 0x340,
	const DWORD CameraCache = 0x370;// Class: PlayerCameraManager.Actor.Object, CameraCacheEntry CameraCache;//[Offset: 0x350,
	const DWORD LocalController = 0x2bb4;// STExtraPlayerController* STPlayerController;//[Offset:
	const DWORD POV = 0x10;// Class: CameraCacheEntry, MinimalViewInfo POV;//[Offset: 0x10,
	const DWORD Location = 0x0;// Class: MinimalViewInfo, Vector Location;//[Offset: 0x0,
	const DWORD Rotation = 0x18;// Class: MinimalViewInfo, Rotator Rotation;//[Offset: 0x18,
	const DWORD FOV = 0x24;// Class: MinimalViewInfo, float FOV;//[Offset: 0x24,

	// Instant hit offsets
	const DWORD CurrentReloadWeapon = 0x1eb4;//up 0x1e9c;// STExtraWeapon* CurrentReloadWeapon;//[Offset:
	const DWORD CurrentReloadWeapon2 = 0x1eb4;// STExtraWeapon* CurrentReloadWeapon;//[Offset:
	const DWORD ShootWeaponEntity = 0xc30;// 0xc10;//up 0xbc0;// ShootWeaponEntity* ShootWeaponEntityComp;//[Offset:
	const DWORD BulletFireSpeed = 0x408;// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object, float BulletFireSpeed;//[Offset:

	// NoRecoil offsets
	const DWORD AccessoriesVRecoilFactor = 0x870;// 0x860;// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object, float AccessoriesVRecoilFactor;//[Offset: 848
	const DWORD AccessoriesHRecoilFactor = 0x874;// 0x864; ///
	const DWORD AccessoriesRecoveryFactor = 0x878;// 0x868; // all + 10

	// vehicle offsets
	const  DWORD VehicleCommon = 0x73c;// 0x700;//up 0x6f8;// VehicleCommonComponent* VehicleCommon;//[Offset: 0x698,
	const  DWORD VhiDrive = 0x71d;// 0x6e1;// 0x6d9;// bool bIsEngineStarted;//(ByteOffset:
	const  DWORD HP = 0x1e4;// 0x1e4;// Class: VehicleCommonComponent.VehicleComponent.LuaActorComponent.ActorComponent.Object, float HP;//[Offset: 0x11c, Size: 4]
	const  DWORD HPMax = 0x1e0;// 0x1e0;// Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float HPMax;//[Offset: 0x118,
	const  DWORD FuelMax = 0x1f8;// 0x1f8;// Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float FuelMax;//[Offset: 0x130,
	const  DWORD Fuel = 0x1fc;// 0x1fc;// Class: VehicleCommonComponent.VehicleComponent.ActorComponent.Object -> float Fuel;//[Offset: 0x134,

	//////SPEED OFFSETS/////
	const DWORD CharacterOverrideAttrs = 0x2230;// CharacterOverrideAttrs CharacterOverrideAttrs;
	//////FastLanding OFFSETS/////
	const DWORD ParachuteComponent = 0xfb8;// 0xfa0;// CharacterParachuteComponent* ParachuteComponent;//[Offset: 0xe88,

	///////
	const DWORD bEnablePlayerPickUpAnim = 0x1560;// Class: STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object, bool bEnablePlayerPickUpAnim;//(ByteOffset: 0, ByteMask: 1, FieldMask: 255)[Offset:

	///////
	const DWORD GameStateBase = 0x128;
	const DWORD AlivePlayerNum = 0x79c;
	const DWORD ElapsedTime = 0x340;// int ElapsedTime;//[Offset:
	const DWORD AliveTeamNum = 0x7a0;
	const DWORD PlayerNum = 0x53c;// int PlayerNum;//[Offset:
	const DWORD CurCircleWave = 0x720;
	const DWORD GameModeID = 0xb28;// FString GameModeID;//[Offset: 0xb30, Size: 0xc]
	const DWORD IsFPPGameMode = 0x680;
	////////////////////////////////
	const DWORD ExtraShootInterval = 0x434;// 0x430;// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object, float ExtraShootInterval;//[Offset:
	////////////////////////////////
	const DWORD CharacterParachuteComponent = 0xfb8;// 0xfa0;// CharacterParachuteComponent* ParachuteComponent;//[Offset: 0xf98, Size: 0x4]
	const DWORD CurrentFallSpeed = 0x294;// float CurrentFallSpeed;//[Offset: 0x2c0, Size: 0x4]
	//////////////////////////////
	const DWORD ShootInterval = 0x42c;// 0x428;// = 0x430;/// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object,  float ShootInterval;//[Offset:
	const DWORD ShotGunVerticalSpread = 0x8c4;// 0x8b4;// Class: ShootWeaponEntity.WeaponEntity.WeaponLogicBaseComponent.ActorComponent.Object,  float ShotGunVerticalSpread;//[Offset:
	const DWORD ShotGunHorizontalSpread = 0x8c8;// 0x8b8; // float ShotGunHorizontalSpread;//[Offset:
	const DWORD GameDeviationFactor = 0x8cc;// 0x8bc; // float GameDeviationFactor;//[Offset:
	const DWORD RecoilKickADS = 0x978;// 0x968;//  float RecoilKickADS;//[Offset:
	const DWORD AnimationKick = 0x994;// 0x984;// float AnimationKick;//[Offset:
	const DWORD LaunchGravityScale = 0x340;// 0x344;//= 0x130; // check : 0x1dc / 0x130// Class: STExtraShootWeaponBulletBase.Actor.Object, float LaunchGravityScale;//[Offset:
	const DWORD SwitchWeaponSpeedScale = 0x1bf4;// 0x1bb4;// Class: STExtraBaseCharacter.STExtraCharacter.UAECharacter.Character.Pawn.Actor.Object, float SwitchWeaponSpeedScale;//[Offset:
	const DWORD Controller = 0x31c;// Class: Pawn.Actor.Object, Controller* Controller;//[Offset:
	const DWORD ControlRotation = 0x318;// Class: Controller.Actor.Object, Rotator ControlRotation;//[Offset:
	// 
}