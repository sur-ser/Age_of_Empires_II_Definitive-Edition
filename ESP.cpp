#include "ESP.h"

#include "Sdk.h"
#include "Renderer.h"
#include "Engine.h"


void ESP::DrawBox(Unit* unit, int32_t color, bool drawName = false)
{
	Vector3 one3 = unit->position;
	one3.x -= unit->pUnitData->collisionX;
	one3.y -= unit->pUnitData->collisionY;
	Vector2 one = Engine::Get()->worldToScreen(one3);

	Vector3 two3 = unit->position;
	two3.x += unit->pUnitData->collisionX;
	two3.y += unit->pUnitData->collisionY;
	Vector2 two = Engine::Get()->worldToScreen(two3);

	Vector3 three3 = unit->position;
	three3.x -= unit->pUnitData->collisionX;
	three3.y += unit->pUnitData->collisionY;
	Vector2 three = Engine::Get()->worldToScreen(three3);

	Vector3 four3 = unit->position;
	four3.x += unit->pUnitData->collisionX;
	four3.y -= unit->pUnitData->collisionY;
	Vector2 four = Engine::Get()->worldToScreen(four3);

	ImVec2 ivOne = ImVec2(one.x, one.y);
	ImVec2 ivTwo = ImVec2(two.x, two.y);
	ImVec2 ivThree = ImVec2(three.x, three.y);
	ImVec2 ivFour = ImVec2(four.x, four.y);


	Renderer::Get()->RenderRect(ivOne, ivFour, ivTwo, ivThree, color);

	if (drawName)
	{
		Vector3 textPos = unit->position;
		Vector2 screenTextPos = Engine::Get()->worldToScreen(textPos);
		ImVec2 ivTextPos = ImVec2(screenTextPos.x, screenTextPos.y);
		Renderer::Get()->RenderText(unit->pUnitData->name, ivTextPos, 16, color, false);
	}
}

void ESP::OnUnitIteration(Unit* unit, Player* player, int playerIndex)
{
	if (playerUnitEsp[playerIndex])
	{
		if (strcmp(unit->pUnitData->name, "FLARE") == 0)
		{
			return; //Dont display annoying flares that Bots use
		}
		DrawBox(unit, colors_hex[0], playerUnitNameEsp[playerIndex]);
	}
}


void ESP::OnMenuPlayerTreenode(Player* player, int playerIndex)
{
	if (ImGui::TreeNode("ESP"))
	{
		ImGui::PushItemWidth(100);
		ImGui::Checkbox("Unit", &playerUnitEsp[playerIndex]);
		ImGui::TreePop();
	}
}

void ESP::OnNeutralUnit(Unit* unit)
{
	if (gaiaEsp)
	{
		std::string unitName = unit->pUnitData->name;
		Vector2 screenPos = Engine::Get()->worldToScreen(unit);

		if (goldESP && strcmp(unitName.c_str(), "GOLDM") == 0)
		{
			DrawBox(unit, 0xFFFFD700);
		}
		if (stoneESP && strcmp(unitName.c_str(), "STONM") == 0)
		{
			DrawBox(unit, 0xFF888c8d);
		}

		if (strcmp(unitName.c_str(), "BOARX") == 0)
		{
			Renderer::Get()->RenderCircleFilled(ImVec2(screenPos.x, screenPos.y), 20, 0x4000ff00);
			Renderer::Get()->RenderText(unitName, ImVec2(screenPos.x, screenPos.y), 16, 0xffffffff);
		}
		if (strcmp(unitName.c_str(), "SHEEPG") == 0)
		{
			Renderer::Get()->RenderCircleFilled(ImVec2(screenPos.x, screenPos.y), 20, 0x400000ff);
			Renderer::Get()->RenderText(unitName, ImVec2(screenPos.x, screenPos.y), 16, 0xffffffff);
		}
		if (strcmp(unitName.c_str(), "WOLFX") == 0)
		{
			Renderer::Get()->RenderCircleFilled(ImVec2(screenPos.x, screenPos.y), 20, 0x40ff0000);
			Renderer::Get()->RenderText(unitName, ImVec2(screenPos.x, screenPos.y), 16, 0xffffffff);
		}

		if (strcmp(unitName.c_str(), "FISHX") == 0 || strcmp(unitName.c_str(), "FISH1") == 0 || strcmp(unitName.c_str(), "FISH2") == 0 || strcmp(unitName.c_str(), "FISH3") == 0 || strcmp(unitName.c_str(), "FISH4") == 0)
		{
			Renderer::Get()->RenderCircleFilled(ImVec2(screenPos.x, screenPos.y), 20, 0x400000ff);
			Renderer::Get()->RenderText(unitName, ImVec2(screenPos.x, screenPos.y), 16, 0xffffffff);
		}
		if (strcmp(unitName.c_str(), "RELIC") == 0)
		{
			Renderer::Get()->RenderCircleFilled(ImVec2(screenPos.x, screenPos.y), 20, 0x40ffffff);
			Renderer::Get()->RenderText(unitName, ImVec2(screenPos.x, screenPos.y), 16, 0xffffffff);
		}
	}
}

void ESP::OnMenuMainWindow()
{
	ImGui::Checkbox("GaiaESP", &gaiaEsp);
	ImGui::Checkbox("GoldESP", &goldESP);
	ImGui::Checkbox("StoneESP", &stoneESP);
}