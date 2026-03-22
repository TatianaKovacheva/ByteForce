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
    cout << "**************************************************\n";
    cout << "*                                                *\n";
    cout << "*               B Y T E F O R C E                *\n";
    cout << "*            Grade 9 Mathematics Edition         *\n";
    cout << "*                                                *\n";
    cout << "**************************************************\n";
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

void showPracticeTasks() {
    bool inModule = true;
    while (inModule) {
        clearScreen();
        printLine();
        cout << "PRACTICE TASKS\n";
        printLine();
        for (int i = 0; i < 2; i++) {
            cout << (i + 1) << ". " << practiceTitles[i] << "\n";
        }
        cout << "0. Back to Main Menu\n";
        cout << "Choose set [0-2]: ";

        int choice = readIntInRange(0, 2);
        if (choice == 0) {
            inModule = false;
        }
        else {
            clearScreen();
            showSingleItem(practiceTitles, practiceContents, choice - 1);
            waitForEnter();
        }
    }
}

void showHomeworkTasks() {
    bool inModule = true;
    while (inModule) {
        clearScreen();
        printLine();
        cout << "HOMEWORK TASKS\n";
        printLine();
        for (int i = 0; i < 3; i++) {
            cout << (i + 1) << ". " << homeworkTitles[i] << "\n";
        }
        cout << "0. Back to Main Menu\n";
        cout << "Choose set [0-3]: ";

        int choice = readIntInRange(0, 3);
        if (choice == 0) {
            inModule = false;
        }
        else {
            clearScreen();
            showSingleItem(homeworkTitles, homeworkContents, choice - 1);
            waitForEnter();
        }
    }
}