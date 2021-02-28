//Homework 6 Question 4 (Printing all divisors of a given integer)
#include <iostream>
#include <cmath>
using namespace std;
void printDivisors(int num);
/*
This function is given a positive integer num,
and prints all of num¡¯s divisors in an ascending
order, separated by a space.
For example, if we call printDivisors(100),
the expected output is:
1 2 4 5 10 20 25 50 100
If we call printDivisors(12),
the expected output is:
1 2 3 4 6 12
*/
int main() {
	int num;
	cout << "Please enter a positive integer >= 2: ";
	cin >> num;
	if (num >= 2)
		printDivisors(num);
	else
		cout << "Invalid input";	
	return 0;
}

//Implemented in time complexity of theta(sqrt(n))
void printDivisors(int num) {
	for (int i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			cout << i << " ";
		}
	}
	for (int i = (int)sqrt(num); i >= 1; i--) {
		if (num % i == 0) {
			cout << num / i << " ";
		}
	}
}