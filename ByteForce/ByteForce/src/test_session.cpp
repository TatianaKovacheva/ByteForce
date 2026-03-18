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