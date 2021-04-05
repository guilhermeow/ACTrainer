#include <iostream>
#include "process.h"
#include "C:\Users\sickog0d\Desktop\FirstTrainer\InfiniteAmmo.cpp"
#include "C:\Users\sickog0d\Desktop\FirstTrainer\Visual.cpp"
#include "C:\Users\sickog0d\Desktop\FirstTrainer\Menu.cpp"

using namespace std;

int main(HWND hwnd)
{

    ProgramVisual();

    hwnd = FindWindow(NULL, "AssaultCube");

    if(hwnd == NULL)
    {
        cout << "I didn't find the process." << endl;
        system("pause");
    } else {
         MenuInfo(false);
         bool InfiniteAmmoStatus = false;

         while(1)
         if(GetAsyncKeyState(VK_F1)) {
             Sleep(200);

             InfiniteAmmoStatus = !InfiniteAmmoStatus;

             switch(InfiniteAmmoStatus)
             {
             case true:
                MenuInfo(true);
                InfiniteAmmo();
                break;
             case false:
                MenuInfo(false);
                break;
             }
         } else if(GetAsyncKeyState(VK_F11)) {
             Sleep(200);
             MessageBox(0, "Trainer has been closed.", "AssaultCube Hack", MB_OK);
             system("pause");
         }
    }
}
