//Homework 8 Question 4 (PIN Authentication)
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
const int NUMBER_OF_DIGITS = 10;
const int UPPER_LIMIT_OF_RANDOM_DIGIT = 3;
const int PIN_LENGTH = 5;
//const int CORRECT_PIN = 05678;
//Prefix '0' represents octal number in C++, so '05678' is illegal.
const int CORRECT_PIN[PIN_LENGTH] = { 0,5,6,7,8 };
int getNThLastDigit(int n, int i);
//This function returns the i-th last digit of a given positive integer n.
void printArray(int arr[], int arrSize);

int main() {
	cout << "Please enter your PIN according to the following mapping:\n"
		<< "PIN:	0 1 2 3 4 5 6 7 8 9\n"
		<< "NUM:	";
	int arr[NUMBER_OF_DIGITS];
	srand(time(0));	//To create the seed for the random number generator
	for (int i = 0; i < NUMBER_OF_DIGITS; i++) {
		arr[i] = (rand() % UPPER_LIMIT_OF_RANDOM_DIGIT) + 1;
		//To generate a random integer between 1 and UPPER_LIMIT_OF_RANDOM_DIGIT
	}
	printArray(arr, NUMBER_OF_DIGITS);
	bool isCorrect = true;
	//Read the PIN from keyboard input as a whole
	int userInput;
	cin >> userInput;
	//Convert the entire input PIN to an array
	int inputPIN[PIN_LENGTH];
	for (int i = 0; i < PIN_LENGTH; i++) {
		inputPIN[i] = getNThLastDigit(userInput, PIN_LENGTH - i);
	}
	for (int i = 0; i < PIN_LENGTH; i++) {
		if (inputPIN[i] != arr[CORRECT_PIN[i]]) {
			isCorrect = false;
			cout << "Your PIN is not correct";
			break;
		}
	}
	if (isCorrect) {
		cout << "Your PIN is correct";
	}
	return 0;
}
int getNThLastDigit(int n, int i) {
	return n % ((int)pow(10, i)) / ((int)pow(10, i - 1));
	//Even if i > log10(n) + 1,
	//the function can still return 0 which is correct
}

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}