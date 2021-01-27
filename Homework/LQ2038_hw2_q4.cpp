//Homework 2 Question 4
#include <iostream>
using namespace std;
int main()
{
	int a, b;
	cout << "Please enter two positive integers, separated by a space:\n";
	cin >> a >> b;
	cout << a << " + " << b << " = " << a + b << endl;
	cout << a << " - " << b << " = " << a - b << endl;
	cout << a << " * " << b << " = " << a * b << endl;
	cout << a << " / " << b << " = " << (a + 0.0) / (b + 0.0) << endl;
	cout << a << " div " << b << " = " << a / b << endl;
	cout << a << " mod " << b << " = " << a % b << endl;
	return 0;
}