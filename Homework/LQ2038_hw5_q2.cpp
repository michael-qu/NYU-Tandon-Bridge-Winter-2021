//Homework 5 Question 2
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	srand(time(0));
	int randNum = (rand() % 100) + 1;
	//cout << randNum << endl;
	cout << "I thought of a number between 1 and 100! Try to guess it.\n"
		<< "Range: [1, 100] , Number of guesses left: 5\n"
		<< "Your guess: ";
	int userInput;
	int guessCount = 1;
	cin >> userInput;
	int rangeMin = 1;
	int rangeMax = 100;
	while (guessCount < 5) {
		if (userInput > randNum) {
			cout << "Wrong! My number is smaller.\n";
			if (userInput < rangeMax) {
				rangeMax = userInput - 1;
			}
		}
		else if(userInput < randNum) {
			cout << "Wrong! My number is bigger.\n";
			if (userInput > rangeMin) {
				rangeMin = userInput + 1;
			}
		}
		else {
			cout << "Congrats! You guessed my number in " << guessCount << " guesses.";
			break;
		}
		cout << endl;
		
		cout << "Range: [" << rangeMin << ", " << rangeMax << "], Number of guesses left: "
			<< 5 - guessCount << endl;
		cout << "Your guess: ";
		cin >> userInput;
		guessCount++;		
	}
	if (guessCount == 5) {
		if (userInput != randNum)
			cout << "Out of guesses! My number is " << randNum;
		else
			cout << "Congrats! You guessed my number in " << guessCount << " guesses.";
	}
	return 0;
}