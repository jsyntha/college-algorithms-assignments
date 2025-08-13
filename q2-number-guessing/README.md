Q2 – Guess The Number (1–1000)



Two implementations of the number-guessing game (max 10 guesses, high/low hints):

\- Console (C++)

\- GUI (Qt Widgets)



What it does:

\- Picks a random number from 1..1000

\- User gets 10 guesses

\- Feedback each turn: Too high / Too low

\- End messages per brief (≤9 tries, exactly 10, or fail)



How to run:

See the READMEs in console/ and gui/ for build/run steps.



Folder structure:

q2-number-guessing/

&nbsp; README.md

&nbsp; console/

&nbsp;   README.md

&nbsp;   src/

&nbsp;     main.cpp

&nbsp; gui/

&nbsp;   README.md

&nbsp;   GUI-q2.pro

&nbsp;   src/

&nbsp;     main.cpp

&nbsp;     mainwindow.h

&nbsp;     mainwindow.cpp

&nbsp;     mainwindow.ui



Notes:

\- Keep binaries and build folders out of Git (handled by the repo’s root .gitignore).

\- The brief is summarized in docs/Question Sheet - Q2.txt.



