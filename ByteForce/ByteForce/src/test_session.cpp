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