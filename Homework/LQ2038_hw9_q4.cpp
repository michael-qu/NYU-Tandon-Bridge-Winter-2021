//Homework 9 Question 4
#include <iostream>
using namespace std;
void oddsKeepEvensFlip(int arr[], int arrSize);
/*
This function gets an array of integers arr and its logical size arrSize.
When called, it should reorder the elements of arr so that:
1. All the odd numbers come before all the even numbers
2. The odd numbers will keep their original relative order
3. The even numbers will be placed in a reversed order (relative to their original order).
For example, if arr = [5, 2, 11, 7, 6, 4],
after calling oddsKeepEvensFlip(arr, 6), arr will be:
[5, 11, 7, 4, 6, 2]
*/

void printArray(int arr[], int arrSize);
int main() {
	//Initialize a heap-dynamic array with a sequence of integers given by user
	cout << "Please enter the logical size of the array:\n";
	int arrSize;
	cin >> arrSize;
	cout << "Please enter " << arrSize << " integers, separated by a space:\n";
	int* arr = new int[arrSize];
	for (int i = 0; i < arrSize; i++) {
		cin >> arr[i];
	}
	//printArray(arr, arrSize);
	oddsKeepEvensFlip(arr, arrSize);
	cout << "The result is:\n";
	printArray(arr, arrSize);
	delete[] arr;
	arr = nullptr;
	return 0;
}


void oddsKeepEvensFlip(int arr[], int arrSize) {
	int* newArr = new int[arrSize];
	int j = 0;
	int k = arrSize - 1;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 != 0) {	//don't use "==1" coz -1%2 = -1
			newArr[j] = arr[i];
			j++;
		}
	}
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] % 2 == 0) {
			newArr[k] = arr[i];
			k--;
		}
	}
	//printArray(newArr, arrSize);
	//arr = newArr;
	//Changing the value of a local variable will only change the array locally,
	//no update will be returned to main function.
	//To update the array in main function, we can only overwrite the value
	//on the memory address pointed by the pointer
	//which is associated with main function instead of this separate function.
	for (int i = 0; i < arrSize; i++) {
		arr[i] = newArr[i];
	}
	delete[] newArr;
	//printArray(arr, arrSize);
}

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}