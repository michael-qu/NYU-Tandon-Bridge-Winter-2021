//Homework 6 Question 3 (Estimation of e)
//e is the base of natural logarithm
#include <iostream>
using namespace std;
double eApprox(int n);
int main() {
	cout.precision(30);
	for (int n = 1; n <= 15; n++) {
		cout << "n = " << n << '\t' << eApprox(n) << endl;
	}
	return 0;
}

//Using incremental approach to achieve time complexity of theta(n)
double eApprox(int n) {
	double res = 1.0;
	double currTerm = 1.0;
	for (int i = 1; i <= n; i += 1) {
		currTerm /= i;
		res += currTerm;		
	}
	return res;
}