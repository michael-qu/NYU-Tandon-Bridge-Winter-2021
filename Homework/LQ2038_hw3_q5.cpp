//Homework 3 Question 5
/*
To prompt for weight (in pounds) and height (in inches) of a person, and
prints the weight status of that person using BMI value.
*/
#include <iostream>
#include <string>
using namespace std;
const double POUND_IN_KILOGRAM = 0.453592;
const double INCH_IN_METER = 0.0254;
int main()
{
	double weight_pound, height_in, weight_kg, height_m, bmi;
	string status;
	cout << "Please enter weight (in pounds): ";
	cin >> weight_pound;
	cout << "Please enter height (in inches): ";
	cin >> height_in;
	weight_kg = weight_pound * POUND_IN_KILOGRAM;
	height_m = height_in * INCH_IN_METER;
	bmi = weight_kg / height_m / height_m;
	if (bmi < 18.5)
		status = "Underweight";
	else if (bmi < 25)
		status = "Normal";
	else if (bmi < 30)
		status = "Overweight";
	else
		status = "Obese";

	cout << "The weight status is: " << status << endl;
	return 0;
}