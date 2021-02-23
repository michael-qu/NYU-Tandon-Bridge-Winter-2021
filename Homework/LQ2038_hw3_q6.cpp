//Homework 3 Question 6
/*
To compute the cost of a long-distance call.
The cost of the call is determined according to the following rate schedule:
• Any call started between 8:00 A.M. and 6:00 P.M., Monday through Friday, is billed at a
rate of $0.40 per minute.
• Any call starting before 8:00 A.M. or after 6:00 P.M., Monday through Friday, is charged
at a rate of $0.25 per minute.
• Any call started on a Saturday or Sunday is charged at a rate of $0.15 per minute.
The input will consist of the day of the week, the time the call started, and the length of the
call in minutes.
The output will be the cost of the call.
*/
#include <iostream>
#include <string>
using namespace std;
const double WEEKDAY_DAY_RATE = 0.4;
const double WEEKDAY_NIGHT_RATE = 0.25;
const double WEEKEND_RATE = 0.15;
int main()
{
	string day;
	int hour, min;
	char temp;
	int length;
	double cost;
	cout << "Please enter the day of the weekof the call:\n"
		<< "(Format: Mo Tu We Th Fr Sa Su)\n";
	cin >> day;
	cout << "Please enter the time the call started (e.g. 23:59): ";
	cin >> hour >> temp >> min;
	cout << "Please enter the length of the call (in mins): ";
	cin >> length;
	//To set the output format with two digits after the decimal point
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);	
	if ((day == "Sa") || (day == "Su")) {
		cost = length * WEEKEND_RATE;
		cout << "The cost of this call is $" << cost << endl;
	}		
	else if (day == "Mo" || day == "Tu" || day == "We" || day == "Th" || day == "Fr") {
		if (hour < 8 || hour > 18)
			cost = length * WEEKDAY_NIGHT_RATE;
		else
			cost = length * WEEKDAY_DAY_RATE;
		cout << "The cost of this call is $" << cost << endl;
	}
	else {
		cout << "Invalid input" << endl;
	}
	return 0;
}