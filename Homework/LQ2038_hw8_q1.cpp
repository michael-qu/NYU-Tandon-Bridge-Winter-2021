//Homework 8 Question 1
//To find the minimum value in a given array
//and print out all the indices it appears in the array.
#include <iostream>
using namespace std;
int minInArray(int arr[], int arrSize);
int main() {
	const int ARRAY_SIZE = 20;
	int arr[ARRAY_SIZE], minVal;
	cout << "Please enter " << ARRAY_SIZE << " integers separated by a space:\n";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		cin >> arr[i];
	}
	minVal = minInArray(arr, ARRAY_SIZE);
	cout << "The minimum value is " << minVal << ", and it is located in the following indices: ";
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (arr[i] == minVal) {
			cout << i << " ";
		}
	}
	return 0;
}
int minInArray(int arr[], int arrSize) {
	int minVal = arr[0];
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] < minVal) {
			minVal = arr[i];
		}
	}
	return minVal;
}