//Homework 4 Question 6
//To print all of the numbers from 1 to n
//that have more even digits than odd digits.
#include <iostream>;
using namespace std;
int main(){
	int n;
	cout << "Please enter n: ";
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int oddCount = 0;
		int evenCount = 0;
		int temp = i;
		while (temp > 0) {
			int currDigit = temp % 10;
			temp /= 10;
			if (currDigit % 2 == 0)
				evenCount++;
			else
				oddCount++;
		}
		if (evenCount > oddCount)
			cout << i << endl;
	}
	return 0;
 }
