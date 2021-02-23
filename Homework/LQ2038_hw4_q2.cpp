//Homework 4 Question 2
//To convert a decimal number to Simplified Roman Numerals System
#include <iostream>
using namespace std;
int main()
{
	int n, i;
	int num1000, num500, num100, num50, num10, num5, num1;
	cout << "Enter decimal number:\n";
	cin >> n;
	num1000 = n / 1000;
	num500 = (n % 1000) / 500;
	num100 = (n % 500) / 100;
	num50 = (n % 100) / 50;
	num10 = (n % 50) / 10;
	num5 = (n % 10) / 5;
	num1 = n % 5;
	cout << n << " is ";
	for (i = 1; i <= num1000; i++)
		cout << "M";
	for (i = 1; i <= num500; i++)
		cout << "D";
	for (i = 1; i <= num100; i++)
		cout << "C";
	for (i = 1; i <= num50; i++)
		cout << "L";
	for (i = 1; i <= num10; i++)
		cout << "X";
	for (i = 1; i <= num5; i++)
		cout << "V";
	for (i = 1; i <= num1; i++)
		cout << "I";

	return 0;
}