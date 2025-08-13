Q2 – Console Version (C++)



Implements the number-guessing game:

\- Random integer 1..1000

\- 10 guesses max

\- Feedback: Too high / Too low

\- End messages:

&nbsp; - Less than 10 tries: Either you know the secret or you got lucky!

&nbsp; - Exactly 10 tries: You know the secret!

&nbsp; - No correct guess in 10: You should be able to do better!



Build instructions:



Using g++ (Linux/Mac/WSL):

g++ -std=c++17 -O2 -o q2\_console src/main.cpp

./q2\_console



Using Visual Studio (Windows):

1\. Create a new Console App (C++).

2\. Add src/main.cpp to the project.

3\. Set as Startup Item and run.



Implementation tips:

\- Random number: std::random\_device rd; std::mt19937 gen(rd()); std::uniform\_int\_distribution<int> dist(1, 1000);

\- Validate input (handle non-numeric; reprompt).

\- Clamp guesses to 1..1000 for user-friendliness.

\- Track attempts; stop at 10 or on success.



Example flow:

Guess a number between 1 and 1000:

500

Too high, try again

250

Too low, try again

...



