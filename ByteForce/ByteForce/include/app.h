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
extern int categoryQuota[4];

extern string lessonTitles[4];
extern string lessonContents[4];

extern string practiceTitles[2];
extern string practiceContents[2];

extern string homeworkTitles[3];
extern string homeworkContents[3];

extern int questionIds[32];
extern string questionCategories[32];
extern string questionTexts[32];
extern string questionOptions[32][4];
extern int questionCorrectIndex[32];
extern int questionPoints[32];

extern string attemptStudentName[200];
extern int attemptScore[200];
extern int attemptMaxScore[200];
extern double attemptPercent[200];
extern int attemptGrade[200];
extern int attemptCategoryObtained[200][4];
extern int attemptCategoryMax[200][4];
extern int attemptCount;

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