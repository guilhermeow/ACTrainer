#include <iostream>

void MenuInfo(bool status) {
    system("cls");
    switch(status) {
    case 0:
        std::cout << "[F1] Infinite Ammo | Status: Disabled" << std::endl;
        break;
    case 1:
        std::cout << "[F1] Infinite Ammo | Status: Enabled" << std::endl;
        break;
    }
    std::cout << "[F11] Leave the Trainer" << std::endl;
}
