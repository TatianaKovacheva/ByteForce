# ByteForce — Grade 9 Mathematics E-School

> A console-based interactive e-school for Grade 9 Mathematics, built in C++17.

---

## 📑 Table of Contents

<p align="center">
  <a href="#-about-the-project"><img src="https://img.shields.io/badge/ABOUT%20THE%20PROJECT-2196F3?style=for-the-badge" /></a>
  <a href="#-how-to-build-and-run"><img src="https://img.shields.io/badge/HOW%20TO%20BUILD%20AND%20RUN-4CAF50?style=for-the-badge" /></a>
  <a href="#️-technologies"><img src="https://img.shields.io/badge/TECHNOLOGIES-FF9800?style=for-the-badge" /></a>
  <a href="#-our-team"><img src="https://img.shields.io/badge/OUR%20TEAM-9C27B0?style=for-the-badge" /></a>
</p>

---

## 🧠 About the Project

ByteForce is a console-based interactive e-school focused on **Grade 9 Mathematics**. It combines structured learning content, practice and homework sets, auto-generated multiple-choice tests, and a full statistics screen — all running in a terminal.

### Key Features

- **Learning Content** — 4 lessons covering Linear Equations, Algebraic Expressions, Geometry, and Statistics Basics.
- **Practice Tasks** — 2 practice sets with worked problems to reinforce each topic.
- **Homework Tasks** — 3 homework assignments for independent study.
- **Test Center** — auto-generated 20-question multiple-choice tests drawn from a bank of 32 questions across 4 categories. Questions are shuffled every run. Tracks student name, score, percentage, and grade.
- **Statistics** — results table for all attempts, best/lowest student, class average, and per-category performance breakdown.

### Test Structure

| Category | Questions in bank | Per test | Points each |
|---|---|---|---|
| Linear Equations | 8 | 6 | 3 |
| Expressions | 8 | 5 | 2 |
| Geometry | 8 | 5 | 2 |
| Statistics | 8 | 4 | 1 |

### Grading Scale

| Percentage | Grade |
|---|---|
| ≥ 90% | 6 |
| ≥ 75% | 5 |
| ≥ 60% | 4 |
| ≥ 45% | 3 |
| < 45% | 2 |

### Why Header Files?

Headers (`.h`) declare interfaces so multiple `.cpp` files can share functions and types without duplication. This keeps the code modular and easier to maintain.

---

## 📁 Project Structure

```
ByteForce/
├── main.cpp                  — entry point; calls mainMenu()
├── include/
│   ├── app.h                 — all shared declarations: arrays, extern globals, function prototypes
│   └── mainMenu.h            — declares mainMenu()
└── src/
    ├── app.cpp               — core utilities: screen clearing, input validation, menu display, content viewers
    ├── mainMenu.cpp          — main loop: initializes content, dispatches menu choices
    ├── test_session.cpp      — test logic: question shuffling, answer checking, grading, result display
    ├── statistics.cpp        — statistics screen: results table, best/worst/average, category breakdown
    └── data.cpp              — all data: lessons, practice sets, homework, 32 questions with options and answers
```

---

## 🚀 How to Build and Run

From the project root, build with a C++17 compiler.

**Linux / macOS (g++):**
```bash
g++ -std=c++17 src/*.cpp main.cpp -Iinclude -o byteforce
./byteforce
```

**Windows (MinGW):**
```cmd
g++ -std=c++17 src/*.cpp main.cpp -Iinclude -o byteforce.exe
byteforce.exe
```

> If `g++` is missing:
> - Ubuntu/Debian: `sudo apt install build-essential`
> - Windows: install [MinGW-w64](https://www.mingw-w64.org/)
>
> A Visual Studio solution (`.slnx` / `.vcxproj`) is also included in the `ByteForce/` subfolder for building directly in Visual Studio.

---

## 🛠️ Technologies

<p align="center">
  <img src="https://skillicons.dev/icons?i=cpp" alt="C++" title="C++" width="50" />
  <img src="https://skillicons.dev/icons?i=visualstudio" alt="Visual Studio" title="Visual Studio" width="50" />
  <img src="https://skillicons.dev/icons?i=git" alt="Git" title="Git" width="50" />
  <img src="https://skillicons.dev/icons?i=github" alt="GitHub" title="GitHub" width="50" />
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/d/df/Microsoft_Office_PowerPoint_%282025%E2%80%93present%29.svg/960px-Microsoft_Office_PowerPoint_%282025%E2%80%93present%29.svg.png" alt="PowerPoint" title="PowerPoint" width="50" />
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/e/e8/Microsoft_Office_Word_%282025%E2%80%93present%29.svg/960px-Microsoft_Office_Word_%282025%E2%80%93present%29.svg.png" alt="Word" title="Word" width="50" />
  <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/0/07/Microsoft_Office_Teams_%282025%E2%80%93present%29.svg/1280px-Microsoft_Office_Teams_%282025%E2%80%93present%29.svg.png" alt="Teams" title="Teams" width="50" />
</p>

---

## 👥 Our Team

| Name | Role |
|---|---|
| [Tatiana Kovacheva](https://github.com/TatianaKovacheva) | Scrum Trainer |
| [Plamen Rusev](https://github.com/PNRusev24) | Front-End Developer / Designer |
| [Mustafa Husein](https://github.com/MustafaMustafa25) | Front-End Developer |
| [Selin Vatansever](https://github.com/SAVatansever24) | Front-End Developer |
