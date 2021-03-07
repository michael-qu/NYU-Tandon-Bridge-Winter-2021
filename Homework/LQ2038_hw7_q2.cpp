//Homework 7 Question 2 (Perfect Numbers and Amicable Numbers)
/*
A perfect number is a positive integer (>= 2) that
is equal to the sum of its proper divisors.
*/
/*
Amicable numbers are two different positive integer (>= 2),
so related that the sum of the proper divisors of each is equal to the other number.
For example, 220 and 284 are amicable numbers, since:
284 = 1 + 2 + 4 + 5 + 10 + 11 + 20 + 22 + 44 + 55 + 110
(They are all proper divisors of 220)
220 = 1 + 2 + 4 + 71 + 142
(They are all proper divisors of 284)
*/

#include <iostream>
#include <cmath>
using namespace std;
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
/*
The function takes as an input a positive integer num (>= 2),
and updates two output parameters with the number of num's proper divisors and their sum.
For example, if this function is called with num=12,
since 1, 2, 3, 4 and 6 are 12s proper divisors,
the function would update the output parameters with the numbers 5 and 16.
The time complexity of this function is designed as theta(sqrt(n))
*/
bool isPerfect(int num);
/*
This functions is given positive integer num (>= 2),
and determines if it is perfect number or not.
*/

int main() {
	int m;
	cout << "Please enter a positive integer M (M>=2): ";
	cin >> m;
	cout << "All the perfect numbers between 2 and " << m << " are:\n";
	//This program works fine when m < 5e5.
	//If m is larger than that, the program will be very slow.
	//so in reality, the perfect numbers that this program can identify are only:
	//6, 28, 496, 8128
	for (int i = 2; i <= m; i++) {
		if (isPerfect(i))
			cout << i << " ";
	}
	cout << endl;
	cout << "All pairs of amicable numbers that are between 2 and " << m << " are:\n";
	
	for (int i = 2; i <= m; i++) {
		int countDivs, j, k;
		analyzeDividors(i, countDivs, j);
		analyzeDividors(j, countDivs, k);
		if (i == k && i < j && j <= m)	//i<j is to make sure that no duplicate pairs are printed
			cout << "(" << i << ", " << j << ")\n";
	}

	////(This is a driver program)
	//int num;
	//int outCountDivs, outSumDivs;
	//char ans;
	//do {		
	//	cout << "num = ";
	//	cin >> num;
	//	analyzeDividors(num, outCountDivs, outSumDivs);
	//	cout << "outCountDivs = " << outCountDivs << endl
	//		<< "outSumDivs = " << outSumDivs << endl;
	//	cout << "Try again? (Y/N)";
	//	cin >> ans;
	//	cout << endl;
	//} while (ans == 'Y' || ans == 'y');
	return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	outCountDivs = 0;
	outSumDivs = 0;
	int i;
	for (i = 1; i < sqrt(num); i++) {
		if (num % i == 0) {
			outCountDivs++;
			outSumDivs += i;
		}
	}
	for (i = (int)sqrt(num); i >= 2; i--) {
		if (num % i == 0) {
			outCountDivs++;
			outSumDivs += num / i;
		}
	}
}

bool isPerfect(int num) {
	int countDivs, sumDivs;
	analyzeDividors(num, countDivs, sumDivs);
	if (num == sumDivs)
		return true;
	else
		return false;
}