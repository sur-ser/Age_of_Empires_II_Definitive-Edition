#pragma once
#include <cstdint>

namespace Offsets
{
	//48 8D 0D ? ? ? ? 41 B8 ? ? ? ? E8 ? ? ? ? 33 C0
	//48 8D 0D ? ? ? ? E8 ? ? ? ? 0F B6 C0 
	int64_t pathfindingSystem = 0x2A070F0; //PathingSystem, World and map correct

	//48 8B 0D ? ? ? ? E8 ? ? ? ? C6 85
	//48 83 3D ? ? ? ? ? 0F 84 ? ? ? ? 45 0F
	int64_t mainScreen = 0x29C50F8; //MainScreenCorrect, MainView COrrect

	//44 89 25 ? ? ? ? 2B
	//41 8B 45 28 99
	int32_t totalPlayers = 0x28900D4; //correct
}