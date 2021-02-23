//Homework 5 Question 1
#include <iostream>
using namespace std;
int main() {
	cout << "Please enter a positive integer:\n";
	int n;
	cin >> n;
	for (int rowCount = 1; rowCount <= n; rowCount++) {
		for (int colCount = 1; colCount <= n; colCount++) {
			int outputNum = rowCount * colCount;
			cout << outputNum << '\t';
		}
		cout << endl;
	}
	return 0;
}