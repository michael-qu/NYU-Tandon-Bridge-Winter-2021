//Homework 9 Question 3 (Four different ways to return an array using pointers)
#include <iostream>
using namespace std;
const int THRESHOLD = 0;
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
/* returns the base address of the array (containing the positive numbers),
and updates the output parameter outPosArrSize with the array’s logical size.
*/
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
/* returns the base address of the array (containing the positive numbers),
and uses the pointer outPosArrSizePtr to update the array’s logical size.
*/
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
/* updates the output parameter outPosArr with the base address of the array (containing the positive numbers),
and the output parameter outPosArrSize with the array’s logical size.
*/
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);
/* uses the pointer outPosArrPtr to update the base address of the array (containing the positive numbers),
and the pointer outPosArrSizePtr to update the array’s logical size.
*/
int aboveThresholdCount(int* arr, int arrSize, int threshold);
//returns the number of elements in array "arr" which are more than a given threshold.
//To count positive elements, just set threshold = 0.
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

	//Section a
	int posArrSize1 = 0;
	int* posArr1 = getPosNums1(arr, arrSize, posArrSize1);
	cout << "The array obtained from function getPosNums1 is:\n";
	printArray(posArr1, posArrSize1);
	delete[] posArr1;
	posArr1 = nullptr;

	//Section b
	int posArrSize2 = 0;
	int* posArr2 = getPosNums2(arr, arrSize, &posArrSize2);
	cout << "The array obtained from function getPosNums2 is:\n";
	printArray(posArr2, posArrSize2);
	delete[] posArr2;
	posArr2 = nullptr;

	//Section c
	int* posArr3 = nullptr;
	int posArrSize3 = 0;	
	getPosNums3(arr, arrSize, posArr3, posArrSize3);
	cout << "The array obtained from function getPosNums3 is:\n";
	printArray(posArr3, posArrSize3);
	delete[] posArr3;
	posArr3 = nullptr;

	//Section d
	int* posArr4 = nullptr;
	int posArrSize4 = 0;
	getPosNums4(arr, arrSize, &posArr4, &posArrSize4);
	cout << "The array obtained from function getPosNums4 is:\n";
	printArray(posArr4, posArrSize4);
	delete[] posArr4;
	posArr4 = nullptr;

	//Return the memory assigned to the heap-dynamic array
	//back to the operating system after use to avoid memory leak.
	delete[] arr;
	return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int posArrSize = aboveThresholdCount(arr, arrSize,THRESHOLD);	
	int* posArr = new int[posArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[j] = arr[i];
			j++;
		}
	}
	outPosArrSize = posArrSize;
	return posArr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	int posArrSize = aboveThresholdCount(arr, arrSize, THRESHOLD);
	int* posArr = new int[posArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[j] = arr[i];
			j++;
		}
	}
	*outPosArrSizePtr = posArrSize;
	return posArr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	int posArrSize = aboveThresholdCount(arr, arrSize, THRESHOLD);
	int* posArr = new int[posArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[j] = arr[i];
			j++;
		}
	}
	outPosArr = posArr;
	outPosArrSize = posArrSize;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	int posArrSize = aboveThresholdCount(arr, arrSize, THRESHOLD);
	int* posArr = new int[posArrSize];
	int j = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			posArr[j] = arr[i];
			j++;
		}
	}
	*outPosArrPtr = posArr;
	*outPosArrSizePtr = posArrSize;
}

int aboveThresholdCount(int* arr, int arrSize, int threshold) {
	int res = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > threshold) {
			res++;
		}
	}
	return res;
}

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}