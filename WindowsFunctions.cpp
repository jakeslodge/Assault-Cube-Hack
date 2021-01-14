#include "WindowsFunctions.h"
#include <iostream>

DWORD WinFunctions::getPID(LPCSTR processName)
{
	DWORD processID;
	//finds Window Handle when given name, first param can be null
	HWND windowHandle = FindWindowA(NULL, processName); // HWND A handle to a window.
	std::cout << windowHandle << "\n";
	GetWindowThreadProcessId(windowHandle, &processID);

	return processID;
}

HANDLE WinFunctions::getHandle(DWORD pid) {
	return OpenProcess(PROCESS_VM_READ | PROCESS_VM_WRITE, false, pid);
}

void WinFunctions::getInfo(LPCSTR processName)
{
	std::cout << processName << "\n";
	processID = getPID(processName);
	std::cout << processID << "\n";
	processHandle = getHandle(processID);
	std::cout << processHandle << "\n";
}