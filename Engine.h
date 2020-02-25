#pragma once
#include <cstdint>

struct Vector2;
struct Vector3;
struct ImVec4;

class World;
class Unit;
class MainScreen;
class Player;
class PlayerArray;

class Engine
{
	static Engine* instance;

	uint64_t base;

	uint32_t playerColors[8] = { 0xff0000ff, 0xffff0000,0xff00ff00,0xffffff00,0xff00ffff,0xffff00ff,0xff7f7f7f,0xffffb400 };

	Engine();

public:
	static Engine* Get();
	World* GetWorld();
	MainScreen* GetMainScreen();
	int GetTotalPlayers();
	PlayerArray* GetPlayerArray();

	Vector2 worldToScreen(Vector3 position);
	Vector2 worldToScreen(Unit* unit);

	uint32_t GetPlayerColor(int colorIndex);
	ImVec4 GetPlayerColorImGUI(int colorIndex);
	Player* GetPlayerByName(char* playername);
};