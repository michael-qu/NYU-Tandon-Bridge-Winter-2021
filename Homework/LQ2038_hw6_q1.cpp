//Homework 6 Question 1 (Fibonacci Numbers Sequence)
#include <iostream>
using namespace std;
int fib(int n);
int main() {
	int num;
	cout << "Please enter a positive integer: ";
	cin >> num;
	cout << fib(num);
	return 0;
}

/*The data type of return value as 'int' is requested by the question itself.
* If n >= 47, the output will be negative
* since the fin value will exceed the limit of 'int' type.
*/
int fib(int n) {
	int res;
	if (n == 1 || n == 2) {
		res = 1;
	}
	else {
		int a = 1, b = 1;
		for (int i = 3; i <= n; i++) {
			res = a + b;
			a = b;
			b = res;
		}
	}
	return res;
}