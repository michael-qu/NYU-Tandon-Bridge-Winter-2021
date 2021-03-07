//Homework 7 Question 1 (Print calender of a given year)
#include <iostream>
using namespace std;
int printMonthCalender(int numOfDays, int startingDay);
/*
This function is given two parameters:
• numOfDays - The number of days in the month
• startingDay – a number 1-7 that represents the day in the week of the first day
in that month (1 for Monday, 2 for Tuesday,..., 6 for Saturday, 7 for Sunday).
The function should:
• Print a formatted monthly calendar of that month
• Return a number 0-6 that represents the day in the week of the last day in that
month (1 for Monday, 2 for Tuesday,..., 6 for Saturday, 0 for Sunday).
• The reason of change in convention is because this return value needs to +1
to get the first day of next month.
e.g. If the last day of this month is Sunday,
then 0+1=1 will get Monday for the first day of next month.
If the last day of this month is Saturday,
then 6+1=7 will get Sunday for the first day of next month.
*/
bool isLeapYear(int year);
/*
A function that takes in a year as input and return true if the year is a leap year.
A year is a leap year in the Gregorian calendar system
if it is divisible by 4 but not by 100, unless it is also divisible by 400.
For example, 1896, 1904, and 2000 were leap years but 1900 was not.
In this homework we only consider AD years.
*/
void printYearCalender(int year, int startingDay);
/*
This function is given two parameters:
• year – an integer that represents a year (e.g. 2016)
• startingDay – a number 1-7 that represents the day in the week of 1/1 in that
year (1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.).
*/
int daysInMonth(int n, bool isLeap);
//To calculate the number of days in a given month.
void printHeaderOfMonth(int month, int year);
//To print the month’s name followed by the year (e.g. March 2016).

int main() {	
	int startingDay;
	int year;
	cout << "Please enter the year: ";
	cin >> year;
	cout << "Please enter a number 1-7 that represents the day in the week\n"
		<< "of 1/1 in that year(1 for Monday, 2 for Tuesday, 3 for Wednesday, etc.)\n";
	cin >> startingDay;
	printYearCalender(year, startingDay);	
	//// (This is a driver program)
	//int numOfDays;	
	//char ans;
	//do {
	//	cout << "numOfDays = ";
	//	cin >> numOfDays;
	//	cout << "startingDay = ";
	//	cin >> startingDay;
	//	cout << "The last day of this month is " << printMonthCalender(numOfDays, startingDay) << endl;
	//	cout << "The first day of next month is " << printMonthCalender(numOfDays, startingDay) + 1 << endl;
	//	cout << "Test again? (Y/N)";
	//	cin >> ans;
	//	cout << endl;
	//} while (ans == 'y' || ans == 'Y');
	return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
	cout << "Mon\t" << "Tue\t" << "Wed\t" << "Thr\t" << "Fri\t" << "Sat\t" << "Sun\n";
	for (int i = 1; i <= startingDay - 1; i++) {
		cout << "\t";
	}
	for (int i = 1; i <= numOfDays; i++) {
		cout << i << "\t";
		if ((startingDay - 1 + i) % 7 == 0) {
			cout << endl;
		}
	}
	cout << endl;
	return (startingDay - 1 + numOfDays) % 7;
}

bool isLeapYear(int year) {
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;	//e.g. 2000 is leap year
	else
		return false;	//e.g. 1900 is not leap year
}

void printYearCalender(int year, int startingDay) {
	bool isLeap = isLeapYear(year);
	for (int monthInd = 1; monthInd <= 12; monthInd++) {
		printHeaderOfMonth(monthInd, year);
		int lastDay = printMonthCalender(daysInMonth(monthInd, isLeap), startingDay);
		cout << endl;
		startingDay = lastDay + 1;		
	}
}

int daysInMonth(int n, bool isLeap) {
	if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10 || n == 12)
		return 31;
	else if (n == 4 || n == 6 || n == 9 || n == 11)
		return 30;
	else if (n == 2 && !isLeap)
		return 28;
	else if (n == 2 && isLeap)
		return 29;
	else
		return 0;
}

void printHeaderOfMonth(int month, int year) {
	switch (month) {
		case 1:
			cout << "January " << year << endl;
			break;
		case 2:
			cout << "February " << year << endl;
			break;
		case 3:
			cout << "March " << year << endl;
			break;
		case 4:
			cout << "April " << year << endl;
			break;
		case 5:
			cout << "May " << year << endl;
			break;
		case 6:
			cout << "June " << year << endl;
			break;
		case 7:
			cout << "July " << year << endl;
			break;
		case 8:
			cout << "August " << year << endl;
			break;
		case 9:
			cout << "September " << year << endl;
			break;
		case 10:
			cout << "October " << year << endl;
			break;
		case 11:
			cout << "November " << year << endl;
			break;
		case 12:
			cout << "December " << year << endl;
			break;
		default:
			cout << "Error" << endl;
	}
}