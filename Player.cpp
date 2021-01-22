#include <windows.h>
#include <iostream>
#include "Player.h"
#include "WindowsFunctions.h"
#include "Offsets.h"

void Player::GetInfo()
{
	ReadProcessMemory(win.processHandle, (LPCVOID)(player_base), &base, sizeof(base), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_health), &health, sizeof(health), nullptr);
	ReadProcessMemory(win.processHandle, (PBYTE*)(base + of_name), &name, sizeof(name), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posx), &position_head.x, sizeof(position_head.x), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posy), &position_head.y, sizeof(position_head.y), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posz), &position_head.z, sizeof(position_head.z), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_team), &team, sizeof(team), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posx_normal), &position_feet.x, sizeof(position_feet.x), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posy_normal), &position_feet.y, sizeof(position_feet.y), nullptr);
	ReadProcessMemory(win.processHandle, (LPCVOID)(base + of_posz_normal), &position_feet.z, sizeof(position_feet.z), nullptr);
	ReadProcessMemory(win.processHandle, (PBYTE*)(of_viewmatrix), &matrix, sizeof(matrix), nullptr);

}

void Player::Print()
{

	std::cout << "~~~~ Player ~~~~" << "\n";


	std::cout << "Name (me): " << health << "\n";
	std::cout << "Health: " << health << "\n";
	std::cout << "Position (head): (" << position_head.x << ", " << position_head.y << ", " << position_head.z << ")\n";
	std::cout << "Position (feet): (" << position_feet.x << ", " << position_feet.y << ", " << position_feet.z << ")\n";
	std::cout << "Team: " << team << "\n";

	std::cout << "\n\n";
}