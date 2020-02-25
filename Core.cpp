#pragma once
#include <Windows.h>
#include <iostream>

#include "imgui\imgui.h"
#include "imgui\imgui_internal.h"


#include "Sdk.h"
#include "Renderer.h"
#include "Core.h"
#include "Engine.h"
#include "FeatureManager.h"

//Features
#include "ResourceInformation.h"
#include "ESP.h"


Core::Core()
{
	//Register Features here
	FeatureManager::Get()->registerFeature(new ResourceInformation());
	FeatureManager::Get()->registerFeature(new ESP());

	FeatureManager::Get()->OnInitialise();
}

void createPlayerTreeNode(Player* player, int playerIndex)
{
	ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1, 1, 1, 1));
	std::string playerText = "Player " + std::to_string(playerIndex);
	if (ImGui::TreeNode(playerText.c_str()))
	{
		ImGui::Text("Player %p", player);
		FeatureManager::Get()->OnMenuPlayerTreenode(player, playerIndex);
		if (ImGui::TreeNode("Units"))
		{
			int buildingCount = 0;
			int infantryCount = 0;
			int calavaryCount = 0;
			for (int i = 0; i < player->pObjectManager->Count; i++)
			{
				Unit* unit = player->pObjectManager->units[i];
				if (!unit) { continue; }

				if (unit->pOwner == player)
				{
					ImGui::Text("%p", unit);
					ImGui::SameLine();
					ImGui::Text("%s", unit->pUnitData->name);

			/*		if (unit->pUnitData->Class == (int16_t)EnumUnitDataClass::Building)
					{
						buildingCount++;
					}
					if (unit->pUnitData->Class == (int16_t)EnumUnitDataClass::Infantry)
					{
						infantryCount++;
					}
					if (unit->pUnitData->Class == (int16_t)EnumUnitDataClass::Cavalry)
					{
						calavaryCount++;
					}*/
				}
			}
			ImGui::Text("Buildings %.d", buildingCount);
			ImGui::Text("Infantry %.d", infantryCount);
			ImGui::Text("Cavalry %.d", calavaryCount);
			ImGui::TreePop();
		}
		ImGui::TreePop();
	}
	ImGui::PopStyleColor();
}

void Core::OnPresent()
{
	printf("OnPresent\n");
	__try
	{
		MainScreen* mainScreen = Engine::Get()->GetMainScreen();
		//printf("mainScreen: %p\n", mainScreen);
		if (!mainScreen)
		{
			return;
		}

		World* world = Engine::Get()->GetWorld();
		printf("world: %p\n", world);


		PlayerArray* playerArray = world->pPlayerArray;
		if (!playerArray)
		{
			return;
		}
		printf("playerArray: %p\n", playerArray);
		int totalPlayers = Engine::Get()->GetTotalPlayers();

		printf("totalPlayers: %d\n", totalPlayers);


		static bool openOverlay = true;
		if (GetAsyncKeyState(VK_INSERT) & 1) { openOverlay = !openOverlay; }

		Renderer::Get()->BeginScene();
		printf("BeginScene\n");
		FeatureManager::Get()->OnDraw();
		printf("OnDraw\n");
		Player* gaiaPlayer = *(Player**)(playerArray);

		if (gaiaPlayer)
		{
			for (int i = 0; i < gaiaPlayer->pObjectManager->Count; i++)
			{
				Unit* unit = gaiaPlayer->pObjectManager->units[i];
				if (!unit)
				{
					continue;
				}
				FeatureManager::Get()->OnNeutralUnit(unit);
			}
		}

		printf("Iterating players\n");
		for (int i = 1; i < totalPlayers; i++)
		{
			Player* player = playerArray->playerData[i].player;
			if (!player)
			{
				continue;
			}
			printf("Player: %p\n", player);
			FeatureManager::Get()->OnPlayerIteration(player, i);
			printf("ObjectManager: %p\n", player->pObjectManager);
			printf("ObjectManagerCount: %d\n", player->pObjectManager->Count);
			for (int j = 0; j < player->pObjectManager->Count; j++)
			{
				Unit* unit = player->pObjectManager->units[j];
				if (!unit)
				{
					continue;
				}
				FeatureManager::Get()->OnUnitIteration(unit, player, i);
			}
		}

		Renderer::Get()->EndScene();

		ImGui::SetNextWindowBgAlpha(0.35f);
		if (openOverlay)
		{
			__try
			{
				if (ImGui::Begin("Age of Empires 2 DE", &openOverlay, ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
				{
					ImGui::Text("World %p", world);
					ImGui::Text("PlayerArray %p", playerArray);
					//ImGui::Text("totalPlayers %d", totalPlayers);
					for (int i = 0; i < totalPlayers; i++)
					{
						createPlayerTreeNode(playerArray->playerData[i].player, i);
					}
					FeatureManager::Get()->OnMenuMainWindow();
				}
			}
			__finally
			{
				ImGui::End();
			}
		}
	}
	__except (1)
	{
		if (Renderer::Get()->inFrame)
		{
			Renderer::Get()->EndScene();
		}
	}
}