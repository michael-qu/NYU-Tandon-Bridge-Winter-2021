//Homework 4 Question 3
//To convert from decimal representation to binary represenation
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cout << "Enter decimal number:\n";
	cin >> n;

	// To find which is the maximum power of 2 within n	
	int maxExp2 = int(log2(n));

	// Another way to get maxExp2 without using log2 function:
	/*int currExp2 = 0;
	while (n/((int)(pow(2,currExp2)))>0) {
		currExp2++;
	}
	int maxExp2 = currExp2 - 1;
	*/

	cout << "The binary representation of " << n << " is ";
	int temp = n;
	for (int i=maxExp2; i>=0; i--) {
		int currPower2 = int(pow(2, i));
		cout << temp / currPower2;
		temp %= currPower2;
	}

	return 0;
}