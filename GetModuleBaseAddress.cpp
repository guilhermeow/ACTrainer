#include "process.h"

uintptr_t GetModuleBaseAddress(DWORD procId, const char *modName)
{
    uintptr_t moduleBase = 0;

     HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, procId);

    if(hSnap != INVALID_HANDLE_VALUE) {
        MODULEENTRY32 modEntry;
        modEntry.dwSize = sizeof(modEntry);

            do {
                    if(Module32First(hSnap, &modEntry)) {
                    if(!strcmp((char *)modEntry.szModule, modName)) {
                        moduleBase = (uintptr_t)modEntry.modBaseAddr;
                        break;
                    }
                     }
                } while(Module32Next(hSnap, &modEntry));
        }
    CloseHandle(hSnap);
    return moduleBase;
}
