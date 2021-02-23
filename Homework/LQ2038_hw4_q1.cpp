//Homework 4 Question 1
//To print the first n even number
#include <iostream>
using namespace std;
int main()
{	
	int n, i;
	// Use While Loop	
	cout << "section a" << endl;
	cout << "Please enter a positive integer: ";
	cin >> n;
	i = 1;
	while (i <= n) {
		cout << 2 * i << endl;
		i++;
	}

	// Use For Loop
	cout << "section b" << endl;
	cout << "Please enter a positive integer: ";
	cin >> n;
	for (i = 1; i <= n; i++)
		cout << 2 * i << endl;

	return 0;
}