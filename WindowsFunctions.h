#pragma once
#include <Windows.h>

//Most of the pointer-type names begin with a prefix of P or LP. Handles refer to a resource that has been loaded into memory.

//Class the have functions for interacting with windows
class WinFunctions
{
	public:
		DWORD processID; //window 32-bit unsigned integer.
		HANDLE processHandle;

		//static means all instances of this class share the same definition for this atribute
		static DWORD getPID(LPCSTR processName); //LPCSTR A pointer to a constant null-terminated string of 8-bit Windows (ANSI) characters.
		static HANDLE getHandle(DWORD pid);

		void getInfo(LPCSTR processName);
		void printInfo();

		//http://www.cplusplus.com/doc/oldtutorial/templates/
		template <class T>
		T Read(LPCVOID address)
		{
			T VALUE;
			ReadProcessMemory(processHandle, (LPCVOID)(address), &VALUE, sizeof(T), 0); //LPCVOID A pointer to a constant of any type.
			return VALUE;
		}
};