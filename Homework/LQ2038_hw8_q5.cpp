//Homework 8 Question 5
#include <iostream>
#include <string>
using namespace std;
int main() {
	cout << "Please enter a name in the following format:\n"
		<< "first name, then middle name or initial, and then last name.\n";
	string firstName, middleName, lastName;
	cin >> firstName >> middleName >> lastName;
	string middleInitial;	//string variable will be initialized as ""
	middleInitial += middleName[0];
	cout << lastName << ", " << firstName << " " << middleInitial <<".";
	return 0;
}