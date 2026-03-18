#ifndef APP_H
#define APP_H

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

extern string categoryNames[4];

void initializeContent();
void clearScreen();


int categoryToIndex(string category);

int readIntInRange(int minValue, int maxValue);

string readNonEmptyLine(string prompt);

void showMainMenu();
void showItems(const string titles[], const string contents[], int count, string sectionName);
void showLearningContent();
void showPracticeTasks();
void showHomeworkTasks();

int gradeFromPercent(double percent);
void shuffleIntArray(int arr[], int n);
void generateTestQuestionIndexes(int selectedIndexes[]);

void runSingleTestAttempt();
void takeGeneratedTest();
void showStatistics();

#endif