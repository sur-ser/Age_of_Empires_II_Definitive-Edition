#pragma once
// Generated using ReClass 2016
#include <cstdint>

struct Vector4
{
	float x;
	float y;
	float z;
	float w;

	Vector4(float x, float y, float z, float w)
	{
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}
};

struct Vector3
{
	float x;
	float y;
	float z;

	Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
};

struct Vector2
{
	float x;
	float y;

	Vector2()
	{
		x = 0;
		y = 0;
	}

	Vector2(float x, float y)
	{
		this->x = x;
		this->y = y;
	}
};


// Generated using ReClass 2016

class World;
class pWorld;
class Map;
class PlayerArray;
class MainScreen;
class GameScreen;
class MainView;
class ObjectManager;
class Player;


class PathfindingSystem
{
public:
	World* GetWorld()
	{
		return *reinterpret_cast<World**>((uint64_t)this + 0x18);
	}
};

class Resources
{
public:
	float food; //0x0000 
	float wood; //0x0004 
	float stone; //0x0008 
	float gold; //0x000C 
	float popSpaceLeft; //0x0010 

}; //Size=0x00C8

class Player
{
public:
	char pad_0x0000[0x28]; //0x0000
	ObjectManager* pObjectManager; //0x0028 
	char pad_0x0030[0x40]; //0x0030
	Resources* pResources; //0x0070 
	char pad_0x0078[0xD8]; //0x0078
	int* Color1; //0x0150 
	int* Color2; //0x0158 
	int* Color3; //0x0160 

}; //Size=0x0188

class World
{
public:
	char pad_0x0000[0x80]; //0x0000
	__int32 gameTime; //0x0080 
	char pad_0x0084[0x1C]; //0x0084
	Map* pMap; //0x00A0 
	char pad_0x00A8[0xB0]; //0x00A8
	float camX; //0x0158 
	float camY; //0x015C 
	char pad_0x0160[0x140]; //0x0160
	PlayerArray* pPlayerArray; //0x02A0 

}; //Size=0x02A8

class pWorld
{
public:
	World* pWorld; //0x0000 

}; //Size=0x0008

class Map
{
public:
	int32_t GetTileSize()
	{
		static int32_t tileOffset = 0x5B38;
		return *reinterpret_cast<int32_t*>((int64_t)this + tileOffset);
	}

}; //Size=0x5CC8

class MainScreen
{
public:
	GameScreen* pGameScreen; //0x0000 
	char pad_0x0008[0x38]; //0x0008

}; //Size=0x0040

class GameScreen
{
public:
	char pad_0x0000[0x48]; //0x0000
	__int32 mouseX; //0x0048 
	__int32 mosueY; //0x004C 
	char pad_0x0050[0x5C]; //0x0050
	__int32 ScreenResX; //0x00AC 
	__int32 ScreenResX2; //0x00B0 
	__int32 ScreenResY; //0x00B4 
	__int32 ScreenResY2; //0x00B8 
	char pad_0x00BC[0xD4]; //0x00BC
	MainView* pMainView; //0x0190 
	char pad_0x0198[0x30]; //0x0198

}; //Size=0x01C8

class MainView
{
public:
	char pad_0x0000[0x2C0]; //0x0000
	float ScreenPosX; //0x02C0 
	float ScreenPosY; //0x02C4 
	float ScreenPosZ; //0x02C8 

}; //Size=0x02CC


class UnitData
{
public:
	char pad_0x0000[0x48]; //0x0000
	__int16 unk; //0x0048 
	__int16 maxHp; //0x004A 
	char pad_0x004C[0x8]; //0x004C
	float collisionX; //0x0054 
	float collisionY; //0x0058 
	float collisionZ; //0x005C 
	char pad_0x0060[0x120]; //0x0060
	char* name; //0x0180 

}; //Size=0x0408


class Unit
{
public:
	char pad_0x0000[0x10]; //0x0000
	UnitData* pUnitData; //0x0010 
	Player* pOwner; //0x0018 
	char pad_0x0020[0x70]; //0x0020
	float fHealth; //0x0090 
	char pad_0x0094[0x4]; //0x0094
	Vector3 position;

}; //Size=0x0250

class ObjectManager
{
public:
	char pad_0x0000[0x8]; //0x0000
	Unit** units; //0x0008 
	__int32 Count; //0x0010 

}; //Size=0x0018


class PlayerData
{
public:
	Player* player; //0x0000
	void* unk; //0x0004
}; //Size: 0x0008

class PlayerArray
{
public:
	PlayerData playerData[8]; //0x0008
}; //Size: 0x0074

class PlayerName
{
public:
	char pad_0000[68]; //0x0000
}; //Size: 0x0044