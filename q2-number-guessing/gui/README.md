Q2 – GUI Version (Qt Widgets)



A small Qt GUI for the number-guessing game:

\- Line edit for guesses

\- Label for feedback (Too high / Too low)

\- Attempts remaining

\- New Game button to reset



Build (Qt Creator):

1\. Open GUI-q2.pro in Qt Creator.

2\. Configure a kit (MinGW or MSVC on Windows, Clang/GCC elsewhere).

3\. Build and Run.



Files:

\- GUI-q2.pro – Qt project file

\- src/main.cpp – app entry point

\- src/mainwindow.h/.cpp/.ui – UI layout and logic



Implementation notes:

\- Generate the secret number with:

&nbsp; int secret = QRandomGenerator::global()->bounded(1, 1001); // 1..1000

\- Keep state in MainWindow:

&nbsp; int secretNumber;

&nbsp; int attemptsUsed; (max 10)

\- Connect UI:

&nbsp; - Enter key on the line edit (returnPressed) -> check guess

&nbsp; - Guess button click -> check guess

&nbsp; - New Game button -> reset state and UI

\- Messages:

&nbsp; - Less than 10 tries: Either you know the secret or you got lucky!

&nbsp; - Exactly 10 tries: You know the secret!

&nbsp; - Fail: You should be able to do better!



UI hints:

\- Disable the input when the game ends; re-enable on New Game.

\- Show attempts remaining (e.g., Attempts: 3/10).

\- Clear feedback on reset.



