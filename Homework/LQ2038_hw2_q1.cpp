//Homework 2 Question 1
#include <iostream>
using namespace std;
int main()
{
	int num25, num10, num5, num1;
	int total_amount, num_dollar, num_cent;
	cout << "Please enter number of coins:\n";
	cout << "# of quarters:";
	cin >> num25;
	cout << "# of dimes:";
	cin >> num10;
	cout << "# of nickels:";
	cin >> num5;
	cout << "# of quarters:";
	cin >> num1;
	total_amount = 25 * num25 + 10 * num10 + 5 * num5 + num1;
	num_dollar = total_amount / 100;
	num_cent = total_amount % 100;
	cout << "The total is " << num_dollar << " dollars and "
		<< num_cent << " cents\n";
	return 0;
}