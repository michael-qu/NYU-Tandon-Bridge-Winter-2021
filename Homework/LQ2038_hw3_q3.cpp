//Homework 3 Question 3
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double a, b, c;
	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;
	if (a == 0) {
		if (b == 0) {
			if (c == 0)
				cout << "This equation has infinite number of solutions";
			else
				cout << "This equation has no solution";
		}			
		else
			cout << "This equation has a single real solution x=" << -c / b << endl;
	}		
	else {
		double delta;
		delta = b * b - 4 * a * c;
		if (delta < 0)
			cout << "This equation has no real solution";
		else if (delta == 0)
			cout << "This equation has a single real solution x=" << -b / 2 / a;
		else {
			double x1, x2;
			x1 = (-b + sqrt(delta)) / 2 / a;
			x2 = (-b - sqrt(delta)) / 2 / a;
			cout << "This equation has two real solutions, x1=" << x1
				<< "; x2=" << x2 << endl;
		}
	}
	
	return 0;
}