#pragma once
#include "Feature.h"

class ESP : public Feature
{
	bool gaiaEsp = false;
	bool goldESP = false;
	bool stoneESP = false;
	bool playerUnitEsp[8] = { false,true,false,false,false,false,false,false };

	bool playerUnitNameEsp[8] = { false,false,false,false,false,false,false,false };
	//bool playerBuildingEsp[8] = { false,true,true,true,true,true,true,true };
	//bool playerBuildingNameEsp[8] = { false,true,true,true,true,true,true,true };
	float colors[8][3];
	uint32_t colors_hex[8] = { 0xff0000ff, 0xffff0000,0xff00ff00,0xffffff00,0xff00ffff,0xffff00ff,0xffffffff,0xffffb400 };

	//Callbacks
	void OnUnitIteration(Unit* unit, Player* player, int playerIndex);
	void OnMenuPlayerTreenode(Player* player, int playerIndex);
	void OnNeutralUnit(Unit* unit);
	void OnMenuMainWindow();

	void DrawBox(Unit* unit, int32_t color, bool drawName);
};