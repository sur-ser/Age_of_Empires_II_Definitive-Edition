#include "ResourceInformation.h"

#include "Sdk.h"
#include "Renderer.h"

#include "Engine.h"


void ResourceInformation::OnMenuPlayerTreenode(Player* player, int playerIndex)
{
	ImGui::Text("Wood: %.f", player->pResources->wood);
	ImGui::Text("Food: %.f", player->pResources->food);
	ImGui::Text("Gold: %.f", player->pResources->gold);
	ImGui::Text("Stone: %.f", player->pResources->stone);
	ImGui::Text("PopSpaceLeft: %.f/%.f", player->pResources->popSpaceLeft);
}