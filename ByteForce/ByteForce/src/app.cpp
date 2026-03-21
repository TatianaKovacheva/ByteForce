#include "../include/app.h"

void printLine() {
    cout << "\n==================================================\n";
}


void clearScreen() {
    system("cls");
}


void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int categoryToIndex(string category) {
    for (int i = 0; i < 4; i++) {
        if (categoryNames[i] == category) {
            return i;
        }
    }
    return -1;
}

int readIntInRange(int minValue, int maxValue) {
    while (true) {
        int value;
        if (cin >> value && value >= minValue && value <= maxValue) {
            cin.ignore(10000, '\n');
            return value;
        }
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter number in [" << minValue << ", " << maxValue << "]: ";
    }
}


string readNonEmptyLine(string prompt) {
    string text;
    while (true) {
        cout << prompt;
        getline(cin, text);
        if (!text.empty()) {
            return text;
        }
        cout << "Input cannot be empty. Try again.\n";
    }
}

void showMainMenu() {
    clearScreen();
    printLine();
    cout << "E-SCHOOL MAIN MENU\n";
    printLine();
    cout << "1. Learning Content\n";
    cout << "2. Practice Tasks\n";
    cout << "3. Homework Tasks\n";
    cout << "4. Test Center\n";
    cout << "5. Statistics\n";
    cout << "6. Exit\n";
    cout << "Choose option [1-6]: ";
}


void showSingleItem(const string titles[], const string contents[], int index) {
    printLine();
    cout << titles[index] << "\n";
    printLine();
    cout << contents[index] << "\n";
}


void showItems(const string titles[], const string contents[], int count, string sectionName) {
    printLine();
    cout << sectionName << "\n";
    printLine();
    for (int i = 0; i < count; i++) {
        cout << "\n[" << (i + 1) << "] " << titles[i] << "\n";
        cout << contents[i] << "\n";
    }
}

void showLearningContent() {
    bool inModule = true;
    while (inModule) {
        clearScreen();
        printLine();
        cout << "LEARNING CONTENT\n";
        printLine();
        for (int i = 0; i < 4; i++) {
            cout << (i + 1) << ". " << lessonTitles[i] << "\n";
        }
        cout << "0. Back to Main Menu\n";
        cout << "Choose lesson [0-4]: ";

        int choice = readIntInRange(0, 4);
        if (choice == 0) {
            inModule = false;
        }
        else {
            clearScreen();
            showSingleItem(lessonTitles, lessonContents, choice - 1);
            waitForEnter();
        }
    }
}