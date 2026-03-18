#include "../includes/app.h"

string categoryNames[4] = { "Linear Equations", "Expressions", "Geometry", "Statistics" };
int categoryQuota[4] = { 6, 5, 5, 4 };

string lessonTitles[4];
string lessonContents[4];

string practiceTitles[2];
string practiceContents[2];

string homeworkTitles[3];
string homeworkContents[3];

int questionIds[32];
string questionCategories[32];
string questionTexts[32];
string questionOptions[32][4];
int questionCorrectIndex[32];
int questionPoints[32];

string attemptStudentName[200];
int attemptScore[200];
int attemptMaxScore[200];
double attemptPercent[200];
int attemptGrade[200];
int attemptCategoryObtained[200][4];
int attemptCategoryMax[200][4];
int attemptCount = 0;

void initializeContent() {
    lessonTitles[0] = "Lesson 1: Linear Equations";
    lessonContents[0] =
        "A linear equation has variable with power 1.\n"
        "Example: 3x - 5 = 10.\n"
        "Goal: isolate x using opposite operations on both sides.\n"
        "Check the result by replacing x in the original equation.";

    lessonTitles[1] = "Lesson 2: Algebraic Expressions";
    lessonContents[1] =
        "Useful formulas:\n"
        "(a+b)^2 = a^2 + 2ab + b^2\n"
        "(a-b)^2 = a^2 - 2ab + b^2\n"
        "a^2 - b^2 = (a-b)(a+b)\n"
        "You simplify by combining like terms and factoring.";

    lessonTitles[2] = "Lesson 3: Geometry in 9th Grade";
    lessonContents[2] =
        "Triangle angle sum is 180 degrees.\n"
        "Pythagorean theorem in right triangle: a^2 + b^2 = c^2.\n"
        "Area of triangle: S = a*h/2.\n"
        "Area of circle: S = pi*r^2, circumference C = 2*pi*r.";

    lessonTitles[3] = "Lesson 4: Statistics Basics";
    lessonContents[3] =
        "Arithmetic mean = sum of values / number of values.\n"
        "Median is the middle value after sorting.\n"
        "Mode is the most frequent value.\n"
        "Range = max value - min value.";

    practiceTitles[0] = "Practice Set A";
    practiceContents[0] =
        "1) Solve: 4x - 7 = 13\n"
        "2) Simplify: 2a + 5a - 3a\n"
        "3) Expand: (x+3)^2";

    practiceTitles[1] = "Practice Set B";
    practiceContents[1] =
        "1) In triangle ABC, A=50 deg and B=60 deg. Find C.\n"
        "2) Find mean of 4, 6, 8, 10.\n"
        "3) Find circumference of circle with r=5 (in pi units).";

    homeworkTitles[0] = "Homework 1";
    homeworkContents[0] =
        "Create and solve 6 linear equations with one unknown.\n"
        "At least 2 must include fractions.";

    homeworkTitles[1] = "Homework 2";
    homeworkContents[1] =
        "Prepare 5 tasks using special products (a+b)^2, (a-b)^2, a^2-b^2.\n"
        "Show full solution steps.";

    homeworkTitles[2] = "Homework 3";
    homeworkContents[2] =
        "Collect 10 real numbers (for example daily steps), then find\n"
        "mean, median, mode and range.";

    questionIds[0] = 1; questionCategories[0] = "Linear Equations"; questionTexts[0] = "Solve: 2x + 5 = 17";
    questionOptions[0][0] = "x=6"; questionOptions[0][1] = "x=11"; questionOptions[0][2] = "x=12"; questionOptions[0][3] = "x=5";
    questionCorrectIndex[0] = 0; questionPoints[0] = 3;

    questionIds[1] = 2; questionCategories[1] = "Linear Equations"; questionTexts[1] = "Solve: 3x - 4 = 11";
    questionOptions[1][0] = "x=5"; questionOptions[1][1] = "x=3"; questionOptions[1][2] = "x=4"; questionOptions[1][3] = "x=6";
    questionCorrectIndex[1] = 0; questionPoints[1] = 3;

    questionIds[2] = 3; questionCategories[2] = "Linear Equations"; questionTexts[2] = "Solve: x/4 = 3";
    questionOptions[2][0] = "x=7"; questionOptions[2][1] = "x=12"; questionOptions[2][2] = "x=1"; questionOptions[2][3] = "x=8";
    questionCorrectIndex[2] = 1; questionPoints[2] = 3;

    questionIds[3] = 4; questionCategories[3] = "Linear Equations"; questionTexts[3] = "Solve: 5x = 45";
    questionOptions[3][0] = "x=8"; questionOptions[3][1] = "x=9"; questionOptions[3][2] = "x=10"; questionOptions[3][3] = "x=12";
    questionCorrectIndex[3] = 1; questionPoints[3] = 3;

    questionIds[4] = 5; questionCategories[4] = "Linear Equations"; questionTexts[4] = "Solve: 7 + x = 2";
    questionOptions[4][0] = "x=9"; questionOptions[4][1] = "x=-5"; questionOptions[4][2] = "x=5"; questionOptions[4][3] = "x=-9";
    questionCorrectIndex[4] = 1; questionPoints[4] = 3;

    questionIds[5] = 6; questionCategories[5] = "Linear Equations"; questionTexts[5] = "Solve: 2(x+3)=14";
    questionOptions[5][0] = "x=4"; questionOptions[5][1] = "x=5"; questionOptions[5][2] = "x=7"; questionOptions[5][3] = "x=2";
    questionCorrectIndex[5] = 0; questionPoints[5] = 3;

    questionIds[6] = 7; questionCategories[6] = "Linear Equations"; questionTexts[6] = "Solve: x - 8 = -3";
    questionOptions[6][0] = "x=-11"; questionOptions[6][1] = "x=11"; questionOptions[6][2] = "x=5"; questionOptions[6][3] = "x=-5";
    questionCorrectIndex[6] = 2; questionPoints[6] = 3;

    questionIds[7] = 8; questionCategories[7] = "Linear Equations"; questionTexts[7] = "Solve: 4x + 1 = 4x + 1";
    questionOptions[7][0] = "No solution"; questionOptions[7][1] = "x=0"; questionOptions[7][2] = "One solution"; questionOptions[7][3] = "Infinitely many solutions";
    questionCorrectIndex[7] = 3; questionPoints[7] = 3;

    questionIds[8] = 9; questionCategories[8] = "Expressions"; questionTexts[8] = "Simplify: 3a + 2a";
    questionOptions[8][0] = "5a"; questionOptions[8][1] = "6a"; questionOptions[8][2] = "a^2"; questionOptions[8][3] = "3a";
    questionCorrectIndex[8] = 0; questionPoints[8] = 2;

    questionIds[9] = 10; questionCategories[9] = "Expressions"; questionTexts[9] = "Expand: (x+2)^2";
    questionOptions[9][0] = "x^2+4"; questionOptions[9][1] = "x^2+2x+4"; questionOptions[9][2] = "x^2+4x+4"; questionOptions[9][3] = "x^2-4x+4";
    questionCorrectIndex[9] = 2; questionPoints[9] = 2;

    questionIds[10] = 11; questionCategories[10] = "Expressions"; questionTexts[10] = "Expand: (a-b)^2";
    questionOptions[10][0] = "a^2-b^2"; questionOptions[10][1] = "a^2-2ab+b^2"; questionOptions[10][2] = "a^2+2ab+b^2"; questionOptions[10][3] = "a^2+b^2";
    questionCorrectIndex[10] = 1; questionPoints[10] = 2;

    questionIds[11] = 12; questionCategories[11] = "Expressions"; questionTexts[11] = "Factor: x^2 - 16";
    questionOptions[11][0] = "(x-4)^2"; questionOptions[11][1] = "(x-8)(x+2)"; questionOptions[11][2] = "(x-4)(x+4)"; questionOptions[11][3] = "x(x-16)";
    questionCorrectIndex[11] = 2; questionPoints[11] = 2;

    questionIds[12] = 13; questionCategories[12] = "Expressions"; questionTexts[12] = "Simplify: 2x - 5x + x";
    questionOptions[12][0] = "-2x"; questionOptions[12][1] = "2x"; questionOptions[12][2] = "-4x"; questionOptions[12][3] = "-3x";
    questionCorrectIndex[12] = 0; questionPoints[12] = 2;

    questionIds[13] = 14; questionCategories[13] = "Expressions"; questionTexts[13] = "Expand: (m+3)(m-3)";
    questionOptions[13][0] = "m^2-9"; questionOptions[13][1] = "m^2+9"; questionOptions[13][2] = "m^2-6m+9"; questionOptions[13][3] = "m^2+6m+9";
    questionCorrectIndex[13] = 0; questionPoints[13] = 2;

    questionIds[14] = 15; questionCategories[14] = "Expressions"; questionTexts[14] = "If a=2 and b=5, then a+b equals";
    questionOptions[14][0] = "10"; questionOptions[14][1] = "7"; questionOptions[14][2] = "3"; questionOptions[14][3] = "25";
    questionCorrectIndex[14] = 1; questionPoints[14] = 2;

    questionIds[15] = 16; questionCategories[15] = "Expressions"; questionTexts[15] = "Simplify: 4(2x-1)";
    questionOptions[15][0] = "8x-4"; questionOptions[15][1] = "8x+4"; questionOptions[15][2] = "6x-1"; questionOptions[15][3] = "8x-1";
    questionCorrectIndex[15] = 0; questionPoints[15] = 2;

    questionIds[16] = 17; questionCategories[16] = "Geometry"; questionTexts[16] = "Angles in a triangle sum to";
    questionOptions[16][0] = "90 deg"; questionOptions[16][1] = "180 deg"; questionOptions[16][2] = "270 deg"; questionOptions[16][3] = "360 deg";
    questionCorrectIndex[16] = 1; questionPoints[16] = 2;

    questionIds[17] = 18; questionCategories[17] = "Geometry"; questionTexts[17] = "In right triangle with legs 6 and 8, hypotenuse is";
    questionOptions[17][0] = "9"; questionOptions[17][1] = "10"; questionOptions[17][2] = "12"; questionOptions[17][3] = "14";
    questionCorrectIndex[17] = 1; questionPoints[17] = 2;

    questionIds[18] = 19; questionCategories[18] = "Geometry"; questionTexts[18] = "Area of triangle with base 10 and height 6 is";
    questionOptions[18][0] = "60"; questionOptions[18][1] = "30"; questionOptions[18][2] = "16"; questionOptions[18][3] = "36";
    questionCorrectIndex[18] = 1; questionPoints[18] = 2;

    questionIds[19] = 20; questionCategories[19] = "Geometry"; questionTexts[19] = "Circumference of circle with radius 4 is";
    questionOptions[19][0] = "4pi"; questionOptions[19][1] = "6pi"; questionOptions[19][2] = "8pi"; questionOptions[19][3] = "16pi";
    questionCorrectIndex[19] = 2; questionPoints[19] = 2;

    questionIds[20] = 21; questionCategories[20] = "Geometry"; questionTexts[20] = "Area of square with side 7 is";
    questionOptions[20][0] = "14"; questionOptions[20][1] = "49"; questionOptions[20][2] = "28"; questionOptions[20][3] = "56";
    questionCorrectIndex[20] = 1; questionPoints[20] = 2;

    questionIds[21] = 22; questionCategories[21] = "Geometry"; questionTexts[21] = "If one angle is 35 deg and another is 65 deg, third angle is";
    questionOptions[21][0] = "80 deg"; questionOptions[21][1] = "90 deg"; questionOptions[21][2] = "100 deg"; questionOptions[21][3] = "70 deg";
    questionCorrectIndex[21] = 0; questionPoints[21] = 2;

    questionIds[22] = 23; questionCategories[22] = "Geometry"; questionTexts[22] = "Area of circle with radius 3 is";
    questionOptions[22][0] = "3pi"; questionOptions[22][1] = "6pi"; questionOptions[22][2] = "9pi"; questionOptions[22][3] = "12pi";
    questionCorrectIndex[22] = 2; questionPoints[22] = 2;

    questionIds[23] = 24; questionCategories[23] = "Geometry"; questionTexts[23] = "A rectangle has sides 5 and 9. Perimeter is";
    questionOptions[23][0] = "14"; questionOptions[23][1] = "28"; questionOptions[23][2] = "45"; questionOptions[23][3] = "18";
    questionCorrectIndex[23] = 1; questionPoints[23] = 2;

    questionIds[24] = 25; questionCategories[24] = "Statistics"; questionTexts[24] = "Mean of 2, 4, 6, 8 is";
    questionOptions[24][0] = "4"; questionOptions[24][1] = "5"; questionOptions[24][2] = "6"; questionOptions[24][3] = "7";
    questionCorrectIndex[24] = 1; questionPoints[24] = 1;

    questionIds[25] = 26; questionCategories[25] = "Statistics"; questionTexts[25] = "Median of 1, 3, 7 is";
    questionOptions[25][0] = "1"; questionOptions[25][1] = "3"; questionOptions[25][2] = "7"; questionOptions[25][3] = "11";
    questionCorrectIndex[25] = 1; questionPoints[25] = 1;

    questionIds[26] = 27; questionCategories[26] = "Statistics"; questionTexts[26] = "Mode of 2, 2, 3, 5 is";
    questionOptions[26][0] = "2"; questionOptions[26][1] = "3"; questionOptions[26][2] = "5"; questionOptions[26][3] = "No mode";
    questionCorrectIndex[26] = 0; questionPoints[26] = 1;

    questionIds[27] = 28; questionCategories[27] = "Statistics"; questionTexts[27] = "Range of 4, 10, 7, 1 is";
    questionOptions[27][0] = "10"; questionOptions[27][1] = "9"; questionOptions[27][2] = "6"; questionOptions[27][3] = "3";
    questionCorrectIndex[27] = 1; questionPoints[27] = 1;

    questionIds[28] = 29; questionCategories[28] = "Statistics"; questionTexts[28] = "Mean of 5 and 9 is";
    questionOptions[28][0] = "6"; questionOptions[28][1] = "7"; questionOptions[28][2] = "8"; questionOptions[28][3] = "9";
    questionCorrectIndex[28] = 1; questionPoints[28] = 1;

    questionIds[29] = 30; questionCategories[29] = "Statistics"; questionTexts[29] = "Median of 2, 4, 6, 8 is";
    questionOptions[29][0] = "4"; questionOptions[29][1] = "6"; questionOptions[29][2] = "5"; questionOptions[29][3] = "8";
    questionCorrectIndex[29] = 2; questionPoints[29] = 1;

    questionIds[30] = 31; questionCategories[30] = "Statistics"; questionTexts[30] = "If all values are increased by 1, the mean";
    questionOptions[30][0] = "decreases by 1"; questionOptions[30][1] = "stays same"; questionOptions[30][2] = "increases by 1"; questionOptions[30][3] = "becomes 0";
    questionCorrectIndex[30] = 2; questionPoints[30] = 1;

    questionIds[31] = 32; questionCategories[31] = "Statistics"; questionTexts[31] = "In data set 3, 3, 4, 5, 5, 5, 8, mode is";
    questionOptions[31][0] = "3"; questionOptions[31][1] = "4"; questionOptions[31][2] = "5"; questionOptions[31][3] = "8";
    questionCorrectIndex[31] = 2; questionPoints[31] = 1;
}