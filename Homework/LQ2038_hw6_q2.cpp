//Homework 6 Question 2 (Printing a ‘pine tree’)
#include <iostream>
using namespace std;
void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);
int main() {
	int n;
	char symbol;
	cout << "Please enter the number of triangles in the tree: ";
	cin >> n;
	cout << "Please enter the character filling the tree: ";
	cin >> symbol;
	printPineTree(n, symbol);
	return 0;
}
/*
To print an n-line triangle,
filled with symbol characters,
shifted m spaces from the left margin.
*/
void printShiftedTriangle(int n, int m, char symbol) {
	int spaceNum = m;
	int symNum = 1;
	//Using incremental approach
	for (int lineCount = 1, spaceNum = m + n - 1, symNum = 1;
		lineCount <= n;
		lineCount += 1, spaceNum -= 1, symNum += 2) {		
		for (int spaceCount = 1; spaceCount <= spaceNum; spaceCount += 1) {
			cout << " ";
		}
		for (int symCount = 1; symCount <= symNum; symCount += 1) {
			cout << symbol;
		}
		cout << endl;
	}
}
/*
To print a sequence of n triangles of increasing sizes
(the smallest triangle is a 2-line triangle),
which form the shape of a pine tree.
The triangles are filled with the symbol character.
*/
void printPineTree(int n, char symbol) {
	for (int i = 1; i <= n; i += 1) {
		printShiftedTriangle(i + 1, n - i, symbol);
	}
}