#include "Engine.h"

#include "Sdk.h"
#include "Offsets.h"
#include "Renderer.h"


Engine* Engine::instance = NULL;

Engine::Engine()
{
	base = (uint64_t)GetModuleHandle(NULL);
	printf("Base: %llu\n", base);
}

Engine* Engine::Get()
{
	if (!instance)
	{
		instance = new Engine();
	}
	return instance;
}

World* Engine::GetWorld()
{
	PathfindingSystem* pathfindingSystem = reinterpret_cast<PathfindingSystem*>(base + Offsets::pathfindingSystem);
	printf("pathfindingSystem: %p\n", pathfindingSystem);
	if (!pathfindingSystem)
	{
		return NULL;
	}
	return pathfindingSystem->GetWorld();
}

MainScreen* Engine::GetMainScreen()
{
	return reinterpret_cast<MainScreen*>(base + Offsets::mainScreen);
}

int Engine::GetTotalPlayers()
{
	return *reinterpret_cast<int32_t*>(base + Offsets::totalPlayers);
}

PlayerArray* Engine::GetPlayerArray()
{
	MainScreen* mainScreen = GetMainScreen();
	if (!mainScreen)
	{
		return NULL;
	}

	World* world = GetWorld();
	if (!world)
	{
		return NULL;
	}

	return world->pPlayerArray;
}

Vector2 Engine::worldToScreen(Vector3 position)
{
	MainScreen* mainScreen = GetMainScreen();
	static int tileSize = GetWorld()->pMap->GetTileSize();
	int tile_width = tileSize * mainScreen->pGameScreen->pMainView->ScreenPosZ;
	int tile_height = tileSize * mainScreen->pGameScreen->pMainView->ScreenPosZ;
	

	float xDelta = position.x - mainScreen->pGameScreen->pMainView->ScreenPosX ;
	float yDelta = position.y - mainScreen->pGameScreen->pMainView->ScreenPosY;

	int xResolution = mainScreen->pGameScreen->ScreenResX;
	int yResolution = mainScreen->pGameScreen->ScreenResY;

	float screenXfinal = ((xDelta + yDelta) / 2) * tile_width + (xResolution / 2);
	float screenYfinal = (((xDelta - yDelta) / 2) * tile_height * -1) / 2 + (yResolution / 2);

	screenYfinal -= position.z * tileSize * mainScreen->pGameScreen->pMainView->ScreenPosZ / 4;

	return Vector2(screenXfinal,screenYfinal);
}

Vector2 Engine::worldToScreen(Unit* unit)
{
	return worldToScreen(unit->position);
}

uint32_t Engine::GetPlayerColor(int colorIndex)
{
	return playerColors[colorIndex];
}

ImVec4 Engine::GetPlayerColorImGUI(int colorIndex)
{
	ImVec4 color;
	switch (colorIndex)
	{
	case 0:
		color = ImVec4(0, 0, 1, 1);
		break;
	case 1:
		color = ImVec4(1, 0, 0, 1);
		break;
	case 2:
		color = ImVec4(0, 1, 0, 1);
		break;
	case 3:
		color = ImVec4(1, 1, 0, 1);
		break;
	case 4:
		color = ImVec4(0, 1, 1, 1);
		break;
	case 5:
		color = ImVec4(1, 0, 1, 1);
		break;
	case 6:
		color = ImVec4(0.5, 0.5, 0.5, 1);
		break;
	case 7:
		color = ImVec4(1, 0.5, 0, 1);
		break;
	}
	return color;
}

Player* Engine::GetPlayerByName(char* playerName)
{
	printf("GetPlayerByName: not implemented\n");
	MainScreen* mainScreen = GetMainScreen();
	if (!mainScreen)
	{
		return NULL;
	}

	World* main = GetWorld();
	if (!main)
	{
		return NULL;
	}

	PlayerArray* playerArray = main->pPlayerArray;
	if (!playerArray)
	{
		return NULL;
	}
	int totalPlayers = GetTotalPlayers();


	for (int i = 0; i < totalPlayers; i++)
	{
		Player* player = playerArray->playerData[i].player;
		if (!player)
		{
			continue;
		}
		//TODO fix
		/*if (strcmp(playerName, player->name) == 0)
		{
			return player;
		}*/
	}
	return NULL;
}
