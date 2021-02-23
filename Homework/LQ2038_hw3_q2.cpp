//Homework 3 Question 2
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string userName;
	int graduationYear, currentYear, yearToGrad;
	string status;
	cout << "Please enter your name: ";
	cin >> userName;
	cout << "Please enter your graduation year: ";
	cin >> graduationYear;
	cout << "Please enter current year: ";
	cin >> currentYear;
	yearToGrad = graduationYear - currentYear;
	if (yearToGrad <= 0)
		status = "Graduated";
	else if (yearToGrad == 1)
		status = "Senior";
	else if (yearToGrad == 2)
		status = "Junior";
	else if (yearToGrad == 3)
		status = "Sophomore";
	else if (yearToGrad == 4)
		status = "Freshman";
	else
		status = "Not in college yet";

	cout << userName << ", you are a "<<status;	
	return 0;
}