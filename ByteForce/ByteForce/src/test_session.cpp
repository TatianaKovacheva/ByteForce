#include "../include/app.h"

void printTestLine() {
    cout << "\n==================================================\n";
}

void waitEnterInTest() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int gradeFromPercent(double percent) {
    if (percent >= 90.0) return 6;
    if (percent >= 75.0) return 5;
    if (percent >= 60.0) return 4;
    if (percent >= 45.0) return 3;
    return 2;
}

void shuffleIntArray(int arr[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void generateTestQuestionIndexes(int selectedIndexes[]) {
    int categoryIndexes[4][8];
    int categoryCounts[4] = { 0, 0, 0, 0 };

    for (int i = 0; i < 32; i++) {
        int c = categoryToIndex(questionCategories[i]);
        if (c >= 0 && categoryCounts[c] < 8) {
            categoryIndexes[c][categoryCounts[c]] = i;
            categoryCounts[c]++;
        }
    }

    int writePos = 0;
    for (int c = 0; c < 4; c++) {
        shuffleIntArray(categoryIndexes[c], categoryCounts[c]);
        for (int k = 0; k < categoryQuota[c]; k++) {
            selectedIndexes[writePos++] = categoryIndexes[c][k];
        }
    }

    shuffleIntArray(selectedIndexes, 20);
}

bool canStartNewAttempt() {
    if (attemptCount >= 200) {
        cout << "\nMaximum stored attempts reached. Restart the program to reset quota.\n";
        waitEnterInTest();
        return false;
    }
    return true;
}
void resetAttemptRow(int index) {
    attemptScore[index] = 0;
    attemptMaxScore[index] = 0;
    attemptPercent[index] = 0.0;
    attemptGrade[index] = 2;

    for (int c = 0; c < 4; c++) {
        attemptCategoryObtained[index][c] = 0;
        attemptCategoryMax[index][c] = 0;
    }
}

int askSingleQuestion(int questionIndex, int orderIndex) {
    clearScreen();
    printTestLine();
    cout << "Question " << (orderIndex + 1) << " of 20\n";
    cout << "Category: " << questionCategories[questionIndex] << " | Points: " << questionPoints[questionIndex] << "\n";
    cout << questionTexts[questionIndex] << "\n";

    for (int j = 0; j < 4; j++) {
        cout << "  " << (j + 1) << ") " << questionOptions[questionIndex][j] << "\n";
    }

    cout << "Your answer [1-4]: ";
    return readIntInRange(1, 4) - 1;
}

void processSingleAnswer(int attemptIndex, int questionIndex, int answerIndex) {
    int categoryIdx = categoryToIndex(questionCategories[questionIndex]);

    attemptMaxScore[attemptIndex] += questionPoints[questionIndex];
    if (categoryIdx >= 0) {
        attemptCategoryMax[attemptIndex][categoryIdx] += questionPoints[questionIndex];
    }

    if (answerIndex == questionCorrectIndex[questionIndex]) {
        attemptScore[attemptIndex] += questionPoints[questionIndex];
        if (categoryIdx >= 0) {
            attemptCategoryObtained[attemptIndex][categoryIdx] += questionPoints[questionIndex];
        }
        cout << "Correct!\n";
    }
    else {
        cout << "Wrong. Correct answer: " << questionOptions[questionIndex][questionCorrectIndex[questionIndex]] << "\n";
    }
}

void finalizeAttemptResult(int attemptIndex) {
    if (attemptMaxScore[attemptIndex] == 0) {
        attemptPercent[attemptIndex] = 0.0;
    }
    else {
        attemptPercent[attemptIndex] = 100.0 * (double)attemptScore[attemptIndex] / (double)attemptMaxScore[attemptIndex];
    }

    attemptGrade[attemptIndex] = gradeFromPercent(attemptPercent[attemptIndex]);
}

void printAttemptResult(int attemptIndex) {
    clearScreen();
    printTestLine();
    cout << "TEST RESULT\n";
    printTestLine();
    cout << "Student: " << attemptStudentName[attemptIndex] << "\n";
    cout << "Score: " << attemptScore[attemptIndex] << " / " << attemptMaxScore[attemptIndex] << "\n";
    cout << fixed << setprecision(2);
    cout << "Percent: " << attemptPercent[attemptIndex] << "%\n";
    cout << "Grade (2-6): " << attemptGrade[attemptIndex] << "\n";
}

void runSingleTestAttempt() {
    if (!canStartNewAttempt()) {
        return;
    }

    clearScreen();
    printTestLine();
    cout << "START NEW TEST\n";
    printTestLine();

    int current = attemptCount;
    attemptStudentName[current] = readNonEmptyLine("Enter student name: ");

    resetAttemptRow(current);

    int selectedIndexes[20];
    generateTestQuestionIndexes(selectedIndexes);

    cout << "\nTest has 20 questions. Choose one option (1-4).\n";

    for (int i = 0; i < 20; i++) {
        int q = selectedIndexes[i];
        int answer = askSingleQuestion(q, i);
        processSingleAnswer(current, q, answer);
    }

    finalizeAttemptResult(current);
    attemptCount++;

    printAttemptResult(current);
    waitEnterInTest();
}

void takeGeneratedTest() {
    bool inModule = true;
    while (inModule) {
        clearScreen();
        printTestLine();
        cout << "TEST CENTER\n";
        printTestLine();
        cout << "1. Start New Test\n";
        cout << "2. Show Number of Attempts\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choose option [0-2]: ";

        int choice = readIntInRange(0, 2);
        if (choice == 0) {
            inModule = false;
        }
        else if (choice == 1) {
            runSingleTestAttempt();
        }
        else {
            cout << "\nSaved attempts: " << attemptCount << "\n";
            waitEnterInTest();
        }
    }
}