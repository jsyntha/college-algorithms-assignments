# Q1 — Binary Search (C++)

This project demonstrates **binary search**, an efficient algorithm for finding an item in a sorted list, implemented in two ways:

- **qt-version/** — Qt Widgets app with a graphical interface showing results and split count.
- **console-version/** — Console program printing results and split count in text form.

> Originally second-year coursework. Cleaned and organized for clarity.

## Build Instructions

### Qt version
1. Install Qt 6 (Creator + toolchain).
2. Open `qt-version/GUI-q1.pro` in Qt Creator.
3. Select a kit (MinGW or MSVC), Build, Run.

### Console version
- Open in your preferred C++ IDE or compile with a standard compiler, e.g.:
  ```bash
  g++ -std=c++17 -O2 -o binsearch console-version/src/*.cpp
  ./binsearch
