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
	
	processID = getPID(processName);
	processHandle = getHandle(processID);
}

void WinFunctions::printInfo()
{
	std::cout << "Pid: " << processID << "\n";
	std::cout << "Handle: " << processHandle << "\n";
}