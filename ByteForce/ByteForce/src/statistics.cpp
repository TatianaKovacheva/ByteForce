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

void printResultsTable() {
    cout << "\nTEST RESULTS TABLE\n";
    cout << "------------------------------------------------------------------------------------------------\n";
    cout << left
        << setw(5) << "No."
        << setw(24) << "Student"
        << setw(12) << "Score"
        << setw(12) << "Max"
        << setw(14) << "Percent(%)"
        << setw(10) << "Grade" << "\n";
    cout << "------------------------------------------------------------------------------------------------\n";

    for (int i = 0; i < attemptCount; i++) {
        cout << left
            << setw(5) << (i + 1)
            << setw(24) << attemptStudentName[i]
            << setw(12) << attemptScore[i]
            << setw(12) << attemptMaxScore[i]
            << setw(14) << roundToTwoDigits(attemptPercent[i])
            << setw(10) << attemptGrade[i] << "\n";
    }

    cout << "------------------------------------------------------------------------------------------------\n";
}

void printCategoryStats(int totalObtained[4], int totalMax[4]) {
    int bestCategory = 0;
    int worstCategory = 0;
    double bestCategoryPercent = -1.0;
    double worstCategoryPercent = 101.0;

    cout << "\nCategory performance:\n";

    for (int c = 0; c < 4; c++) {
        double categoryPercent = (totalMax[c] == 0)
            ? 0.0
            : 100.0 * (double)totalObtained[c] / (double)totalMax[c];

        cout << "- " << categoryNames[c] << ": " << roundToTwoDigits(categoryPercent) << "% ("
            << totalObtained[c] << "/" << totalMax[c] << ")\n";

        if (categoryPercent > bestCategoryPercent) {
            bestCategoryPercent = categoryPercent;
            bestCategory = c;
        }
        if (categoryPercent < worstCategoryPercent) {
            worstCategoryPercent = categoryPercent;
            worstCategory = c;
        }
    }

    cout << "\nHighest category success: " << categoryNames[bestCategory] << " (" << roundToTwoDigits(bestCategoryPercent) << "%)\n";
    cout << "Lowest category success: " << categoryNames[worstCategory] << " (" << roundToTwoDigits(worstCategoryPercent) << "%)\n";
}

void printStatisticsScreen() {
    clearScreen();
    printStatsLine();
    cout << "STATISTICS\n";
    printStatsLine();

    if (attemptCount == 0) {
        cout << "No test attempts yet.\n";
        return;
    }

    int bestIndex = findBestStudentIndex();
    int worstIndex = findWorstStudentIndex();
    double averagePercent = calculateAveragePercent();
    int totalObtained[4];
    int totalMax[4];

    calculateCategoryTotals(totalObtained, totalMax);

    printResultsTable();

    cout << "\nSUMMARY\n";
    cout << "Best student: " << attemptStudentName[bestIndex] << " (" << roundToTwoDigits(attemptPercent[bestIndex]) << "%)\n";
    cout << "Lowest student: " << attemptStudentName[worstIndex] << " (" << roundToTwoDigits(attemptPercent[worstIndex]) << "%)\n";
    cout << "Average result: " << roundToTwoDigits(averagePercent) << "%\n";
    cout << "Total attempts: " << attemptCount << "\n";

    printCategoryStats(totalObtained, totalMax);
}

void showStatistics() {
    printStatisticsScreen();
    waitEnterInStats();
}
