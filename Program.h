#ifndef PROGRAM_H_INCLUDED
#define PROGRAM_H_INCLUDED

#include <vector>
#include <conio.h>
#include <windows.h>
#include <TlHelp32.h>

uintptr_t GetModuleBaseAddress(DWORD processId, const char *modName);
uintptr_t FindDMAAddy(HANDLE hProc, uintptr_t ptr, std::vector<unsigned int> offsets);
DWORD GetProcId(const wchar_t* name);

#endif
