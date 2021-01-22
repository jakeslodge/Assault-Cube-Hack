// AC.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "WindowsFunctions.h"
#include "Player.h"

int main()
{
    std::cout << "trying to find AC cube\n";
    WinFunctions win;
    win.getInfo("AssaultCube");

    Player player(win);
    player.GetInfo();
    player.Print();
}

