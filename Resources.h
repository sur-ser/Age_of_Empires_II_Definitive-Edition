#pragma once


class Ressources
{
public:
	float food; //0x0000
	float wood; //0x0004
	float stone; //0x0008
	float gold; //0x000C
	float popSpaceLeft; //0x0010
	char pad_0014[4]; //0x0014
	float age; //0x0018
	char pad_001C[16]; //0x001C
	float CurrentPop; //0x002C
	char pad_0030[28]; //0x0030
	float unitProduced; //0x004C
	char pad_0050[4]; //0x0050
	float techUpgradeCount; //0x0054
	float percentExplored; //0x0058
	char pad_005C[36]; //0x005C
	float gameMaxPop; //0x0080
	char pad_0084[12]; //0x0084
	float farmFoodAmount; //0x0090
	float villagerCount; //0x0094
	char pad_0098[8]; //0x0098
	float infantryCount; //0x00A0
	char pad_00A4[24]; //0x00A4
	float goldRate; //0x00BC
	char pad_00C0[124]; //0x00C0
	float stoneRate; //0x013C
	float unitsQueueCount; //0x0140
	float builingProducingCount; //0x0144
	char pad_0148[24]; //0x0148
	float fishTrapAmount; //0x0160
	char pad_0164[400]; //0x0164
	float chopRate; //0x02F4
	float foodRate; //0x02F8
	float relicGoldRate; //0x02FC
	char pad_0300[12]; //0x0300
	float construcRateMaybe; //0x030C
	char pad_0310[48]; //0x0310
}; //Size: 0x0340
