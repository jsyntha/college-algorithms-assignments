# Qt Version — Binary Search

**What it is:**  
A Qt Widgets app that binary-searches a sorted list of names and shows the split count.

**When:**  
Second-year coursework for algorithms + Qt basics.

## How to Run
1. Open `GUI-q1.pro` in Qt Creator (Qt 6).
2. Configure a kit and build.
3. Run the app, type a name from the list (e.g., "Amy", "Jon", "Tom"), and click Search.

## Features
- Bubble sorts a fixed list of names.
- Performs binary search and counts the number of splits.
- Displays search result, position, and split count in the UI.

## Next Steps
- Make search case-insensitive.
- Allow the user to add/remove names dynamically.
- Highlight the mid index each iteration to visualize the search process.
- Extract the search logic into a pure function and add a simple unit test.
