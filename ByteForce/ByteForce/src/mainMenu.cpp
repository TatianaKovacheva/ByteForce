#include "../include/mainMenu.h"

void mainMenu() {
   

    srand((unsigned int)time(0));
    clearScreen();

    cout << "==============================================\n";
    cout << "   E-SCHOOL: Grade 9 Mathematics Edition\n";
    cout << "==============================================\n";

    bool running = true;
    while (running) {
        showMainMenu();
        int choice = readIntInRange(1, 6);

        switch (choice) {
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
        
            break;
        case 6:
            running = false;
            cout << "Goodbye!\n";
            break;
        }
    }
}
