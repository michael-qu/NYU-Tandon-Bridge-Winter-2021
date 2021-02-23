//Homework 4 Question 5
//To print a textual image of an hourglass made of 2n lines with asterisks (*)

#include <iostream>
using namespace std;
int main()
{
	int n;
	cout << "Please enter n: ";
	cin >> n;
	int numOfSpace;
	int numOfAsterisk;
	for (int i = 1; i <= n; i++) {
		numOfSpace = i - 1;
		numOfAsterisk = 2 * (n - i) + 1;
		for (int j = 1; j <= numOfSpace; j++) {
			cout << " ";
		}
		for (int k = 1; k <= numOfAsterisk; k++) {
			cout << "*";
		}
		cout << endl;
	}
	for (int i = 1; i <= n; i++) {
		numOfSpace = n - i;
		numOfAsterisk = 2 * i - 1;
		for (int j = 1; j <= numOfSpace; j++) {
			cout << " ";
		}
		for (int k = 1; k <= numOfAsterisk; k++) {
			cout << "*";
		}
		cout << endl;
	}
		
	return 0;
}