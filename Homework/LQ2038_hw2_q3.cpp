//Homework 2 Question 3
#include <iostream>
using namespace std;
int main()
{
	int day1, day2, hour1, hour2, min1, min2;
	int total_min, day, hour, min;
	cout << "Please enter the number of days John has worked: ";
	cin >> day1;
	cout << "Please enter the number of hours John has worked: ";
	cin >> hour1;
	cout << "Please enter the number of minutes John has worked: ";
	cin >> min1;
	cout << endl;
	cout << "Please enter the number of days Bill has worked: ";
	cin >> day2;
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> hour2;
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> min2;
	cout << endl;
	total_min = (day1 + day2) * 24 * 60 + (hour1 + hour2) * 60 + min1 + min2;
	day = total_min / (24 * 60);
	hour = (total_min % (24 * 60)) / 60;
	min = total_min % 60;
	cout << "The total time both of them worked together is: " << day
		<< " days, " << hour << " hours and " << min << " minutes.\n";	
	return 0;
}