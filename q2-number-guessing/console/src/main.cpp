#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	srand(time(0));
	int answer = rand() % 1000 + 1;

	int first = 1;
	int last = 1000;
	int guess;
	int attempts = 0;
	bool found = false;

	cout << "Guess a number between 1 & 1000!\n";
	// DEBUG LINE
	cout << "DEBUGGER\n";
	cout << "Answer: " << answer << endl;
	cout << endl;

	while (attempts < 10 && !found) {
		cout << "Enter your guess: ";
		cin >> guess;
		attempts++;
		cout << "Current guess: " << attempts << endl;

		if (guess < answer) {
			cout << "Too low, try again!\n";
			first = guess + 1;
			// DEBUG LINE
			cout << "Range narrowed to: " << first << " - " << last << endl;
		}
		else if (guess > answer) {
			cout << "Too high, try again!\n";
			last = guess - 1;
			// DEBUG LINE
			cout << "Range narrowed to: " << first << " - " << last << endl;
		}
		else {
			cout << "Correct! You guessed the number!\n";
			found = true;
		}
	}

	if (!found) {
		cout << "You should be able to do better!\n";
	}
	else if (attempts < 10) {
		cout << "Either you know the secret or you got lucky!\n";
	}
	else {
		cout << "You know the secret!\n";
	}
}