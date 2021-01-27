//Homework 2 Question 2
#include <iostream>
using namespace std;
int main()
{
	int num25, num10, num5, num1;
	int total_amount, num_dollar, num_cent;
	cout << "Please enter your amount in the format of dollars and cents separated by a space:\n";
	cin >> num_dollar >> num_cent;
	cout << num_dollar << " dollars and " << num_cent << "cents are:\n";
	total_amount = 100 * num_dollar + num_cent;
	num25 = total_amount / 25;
	num10 = (total_amount % 25) / 10;
	num5 = (total_amount % 25) % 10 / 5;
	num1 = total_amount % 5;
	cout << num25 << " quarters, " << num10 << " dimes, " << num5 << " nickels and "
		<< num1 << " pennies";
	return 0;
}