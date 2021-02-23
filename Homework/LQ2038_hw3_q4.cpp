//Homework 3 Question 4 (Round a real number without cmath library)
#include <iostream>
using namespace std;
int main()
{
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;
	double x;
	int result;
	int methodNo;
	cout << "Please enter a Real number: ";
	cin >> x;
	cout << "Choose your rounding method:\n";
	cout << "1. Floor round\n";
	cout << "2. Ceiling round\n";
	cout << "3. Round to the nearest whole number\n";
	cin >> methodNo;
	if (x == (int)x) {
		result = (int)x;
	}
	else {
		switch (methodNo) {
			case FLOOR_ROUND:
				if (x >= 0.0)
					result = (int)x;
				else
					result = (int)x - 1;
				break;
			case CEILING_ROUND:
				if (x >= 0.0)
					result = (int)x + 1;
				else
					result = (int)x;
				break;
			case ROUND: {
				double decimalPart;
				if (x >= 0.0) {
					decimalPart = (double)(x - (int)x);
					if (decimalPart < 0.5) {
						result = (int)x;
						break;
					}
					else {
						result = (int)x + 1;
						break;
					}
				}
				else {
					decimalPart = (double)((int)x - x);
					if (decimalPart < 0.5) {
						result = (int)x;
						break;
					}
					else {
						result = (int)x - 1;
						break;
					}
				}				
			}
		}
	}	
	cout << result << endl;
	return 0;
}