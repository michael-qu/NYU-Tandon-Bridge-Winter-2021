//Homework 4 Question 4
//To calculate geometric mean for a sequence of numbers
//section a: List headed by size
//section b: Exit on a sentinel value
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int length, prod;
	double geom_mean;
	cout << "section a\n";
	prod = 1;
	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << "Please enter your sequence:\n";
	for (int i = 1; i <= length; i++) {
		int x;
		cin >> x;
		prod *= x;
	}
	geom_mean = pow(double(prod), 1 / double(length));
	cout << "The geometric mean is: " << geom_mean << endl;
	cout << endl;

	cout << "section b\n";
	cout << "Please enter a non-empty sequence of positive integers,"
		<< "each one in a separate line. "
		<< "End your sequence by typing - 1:\n";
	prod = 1;
	length = 0;
	int x;
	cin >> x;
	while (x != -1) {
		prod *= x;
		length++;
		cin >> x;
	}
	geom_mean = pow(double(prod), 1 / double(length));
	cout << "The geometric mean is: " << geom_mean << endl;

	return 0;
}