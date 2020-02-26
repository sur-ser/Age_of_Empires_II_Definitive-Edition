#pragma once
#include <cstdint>

namespace Offsets
{
	//48 8D 0D ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 33 C0
	int64_t pathfindingSystem = 0x2882C00;

	//48 8B 0D ? ? ? ? E8 ? ? ? ? C6 85
	int64_t mainScreen = 0x2870828;

	//44 89 25 ? ? ? ? 2B
	int32_t totalPlayers = 0x2743C74;
}