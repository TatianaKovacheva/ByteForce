#include "../include/app.h"

void printStatsLine() {
    cout << "\n==================================================\n";
}

void waitEnterInStats() {
    cout << "\nPress Enter to continue...";
    cin.get();
}

int findBestStudentIndex() {
    int bestIndex = 0;

    for (int i = 1; i < attemptCount; i++) {
        if (attemptPercent[i] > attemptPercent[bestIndex]) {
            bestIndex = i;
        }
    }

    return bestIndex;
}

int findWorstStudentIndex() {
    int worstIndex = 0;

    for (int i = 1; i < attemptCount; i++) {
        if (attemptPercent[i] < attemptPercent[worstIndex]) {
            worstIndex = i;
        }
    }

    return worstIndex;
}

double calculateAveragePercent() {
    double sumPercent = 0.0;

    for (int i = 0; i < attemptCount; i++) {
        sumPercent += attemptPercent[i];
    }

    return sumPercent / (double)attemptCount;
}

void calculateCategoryTotals(int totalObtained[4], int totalMax[4]) {
    for (int i = 0; i < 4; i++) {
        totalObtained[i] = 0;
        totalMax[i] = 0;
    }

    for (int i = 0; i < attemptCount; i++) {
        for (int c = 0; c < 4; c++) {
            totalObtained[c] += attemptCategoryObtained[i][c];
            totalMax[c] += attemptCategoryMax[i][c];
        }
    }
}

double roundToTwoDigits(double value) {
    return (int)(value * 100 + 0.5) / 100.0;
}