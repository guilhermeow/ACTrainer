#include "program.h"
#include "C:\Users\sickog0d\Desktop\FirstTrainer\GetModuleBaseAddress.cpp"
#include "C:\Users\sickog0d\Desktop\FirstTrainer\FindDMAAddy.cpp"

using namespace std;

int InfiniteAmmo()
{
    HWND hwnd = FindWindow(0, "AssaultCube");
    DWORD procId = 0;
    GetWindowThreadProcessId(hwnd, &procId);

    uintptr_t base = GetModuleBaseAddress(procId, "ac_client.exe");

    HANDLE hProcess = 0;
    hProcess = OpenProcess(PROCESS_ALL_ACCESS, false, procId);

    uintptr_t dynamicBase = base + 0x10F4F4;
    uintptr_t ammoAddress = FindDMAAddy(hProcess, dynamicBase, { 0x150 });

    int newAmmo = 99999;

    WriteProcessMemory(hProcess, (BYTE*)ammoAddress, &newAmmo, sizeof(newAmmo), nullptr);
}
