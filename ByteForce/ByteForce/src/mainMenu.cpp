#include "../include/mainMenu.h"

void mainMenu() {
   
    initializeContent();
    srand((unsigned int)time(0));
    clearScreen();

    cout << "**************************************************\n";
    cout << "*                                                *\n";
    cout << "*               B Y T E F O R C E                *\n";
    cout << "*            Grade 9 Mathematics Edition         *\n";
    cout << "*                                                *\n";
    cout << "**************************************************\n";

    bool running = true;
    while (running) {
        showMainMenu();
        int choice = readIntInRange(1, 6);

        switch (choice) {
        case 1:
            showLearningContent();
            break;
        case 2:
            showPracticeTasks();
            break;
        case 3:
            showHomeworkTasks();
            break;
        case 4:
            takeGeneratedTest();
            break;
        case 5:
            showStatistics();
            break;
        case 6:
            running = false;
            cout << "Goodbye!\n";
            break;
        }
    }
}
