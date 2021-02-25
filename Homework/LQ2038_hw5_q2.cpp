//Homework 5 Question 2 (Number Guessing Game)
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main() {
	const int MAX_GUESS_ALLOWED = 5;	
	srand(time(0));	//To create the seed for the random number generator
	int randNum = (rand() % 100) + 1; //Generate a random number between 1 and 100
	cout << "I thought of a number between 1 and 100! Try to guess it.\n"
		<< "Range: [1, 100] , Number of guesses left: " << MAX_GUESS_ALLOWED << endl
		<< "Your guess: ";
	int userInput;
	int guessCount = 1;
	cin >> userInput;
	int rangeMin = 1;
	int rangeMax = 100;
	while (guessCount < MAX_GUESS_ALLOWED) {
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
			<< MAX_GUESS_ALLOWED - guessCount << endl;
		cout << "Your guess: ";
		cin >> userInput;
		guessCount++;		
	}
	if (guessCount == MAX_GUESS_ALLOWED) {
		if (userInput != randNum) {
			cout << "Out of guesses! My number is " << randNum;
		}			
		else {
			cout << "Congrats! You guessed my number in " << guessCount << " guesses.";
		}			
	}
	return 0;
}