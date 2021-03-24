//Homework 8 Question 3
#include <iostream>
using namespace std;
void reverseArray(int arr[], int arrSize);
/* This function takes arr, an array of integers, and its size, arrSize.
When called, it reorders the elements of the array to appear in a reverse order.
For example, if arr is an array containing [1, 2, 3, 4],
after calling reverseArray, arr will look like: [4, 3, 2, 1].
*/
void removeOdd(int arr[], int& arrSize);
/* This function takes arr, an array of integers, and its logical size, arrSize.
When called, the function alters arr so that the only numbers in it at the end are the even ones,
which should remain in their original relative order.
Additionally, the function updates arrSize so it contains the new logical size of the array
after removing the odd numbers (note that arrSize is a parameter used both for input
and output).
For example, if arr is an array containing [1, 2, 3, 4],
after calling removeOdd, arr will look like: [2, 4],
and the parameter arrSize will update to 2.
Notice the values in arr[2] and arr[3] are discarded (they are still physically in the memory
since the physical size of the static array cannot be changed any more after definition,
but they are not counted into the logical size).
*/
void splitParity(int arr[], int arrSize);
/* This function takes arr, an array of integers, and its size, arrSize.
When called, the function changes the order of numbers in arr so that
all the odd numbers will appear first, and all the even numbers will appear last.
Note that the inner order of the odd numbers and the inner order of the even numbers don’t matter.
For example, if arr is an array containing [1, 2, 3, 4],
after calling splitParity, arr could look like: [3, 1, 2, 4].
*/
void printArray(int arr[], int arrSize);
void swap(int& a, int& b);
int main() {
	//My own test case
	/*const int arrOriginalSize = 7;
	cout << "Please enter " << arrOriginalSize << " integers separated by a space:\n";
	int arr[arrOriginalSize];
	for (int i = 0; i < arrOriginalSize; i++) {
		cin >> arr[i];
	}
	printArray(arr, arrOriginalSize);
	reverseArray(arr, arrOriginalSize);
	printArray(arr, arrOriginalSize);
	splitParity(arr, arrOriginalSize);
	printArray(arr, arrOriginalSize);
	int arrCurrentSize = arrOriginalSize;
	removeOdd(arr, arrCurrentSize);
	printArray(arr, arrCurrentSize);*/

	//Test cases provided by the question
	int arr1[10] = { 9, 2, 14, 12, -3 };
	int arr1Size = 5;
	int arr2[10] = { 21, 12, 6, 7, 14 };
	int arr2Size = 5;
	int arr3[10] = { 3, 6, 4, 1, 12 };
	int arr3Size = 5;
	reverseArray(arr1, arr1Size);
	printArray(arr1, arr1Size);
	removeOdd(arr2, arr2Size);
	printArray(arr2, arr2Size);
	splitParity(arr3, arr3Size);
	printArray(arr3, arr3Size);
	return 0;
}
void reverseArray(int arr[], int arrSize) {
	int i = 0, j = arrSize - 1;
	//Using i++, j-- and i<j to ensure the entire array
	//is traversed only once so that the time complexity
	//will be theta(n)
	while (i < j) {
		swap(arr[i], arr[j]);
		i++;
		j--;
	}
}
void removeOdd(int arr[], int& arrSize) {
	int evenCount = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0) {
			arr[evenCount] = arr[i];
			evenCount++;
		}
	}
	arrSize = evenCount;
}
void splitParity(int arr[], int arrSize) {
	int i = 0, j = arrSize - 1;
	//Using i++, j-- and i<j to ensure the entire array
	//is traversed only once so that the time complexity
	//will be theta(n)
	while (i < j) {
		//Look for the first even element
		while (arr[i] % 2 != 0) {
			i++;
		}
		//Look for the last odd element
		while (arr[j] % 2 == 0) {
			j--;
		}
		//Swap the even element in the front
		//with the odd element at the back
		if (i < j) {
			swap(arr[i], arr[j]);
		}
	}
}
void printArray(int arr[], int arrSize) {
	int i;
	for (i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

