#pragma once
#include "WindowsFunctions.h"
#include "Structs.h"

class Player {
private:
	WinFunctions win;

public:

	char name[20];
	int base;
	int health;
	float matrix[16];
	vec2d_f screen;
	vec3d_f position_head;
	vec3d_f position_feet;
	int team;

	Player(WinFunctions wFunction)
	{
		win = wFunction;
	}

	void GetInfo();
	void Print();

};
