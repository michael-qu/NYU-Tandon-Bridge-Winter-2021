//Homework 8 Question 6
/*
To read in a line of text and outputs the line with all the digits
in all-integer-numbers replaced with 'x'. e.g.
Input:
My userID is john17 and my 4 digit pin is 1234 which is secret
Output:
My userID is john17 and my x digit pin is xxxx which is secret
If a digits is part of a word, then the digit is not changed to an 'x'.
For example, john17 is NOT changed to johnxx.
Assume that the text entered by the user will contain only letters
(upper case or lower case), digits and spaces.
*/
#include <iostream>
#include <string>
using namespace std;
const char SYMBOL = 'x';	//Replace words with pure digits using this symbol
bool isOnlyDigit(string str);
int findNextNonSpaceChar(string str, int i);
//This function is to find the index of the next non-space character in str after index i.
//-1 will be returned if there is no non-space character found after index i, 
//or the given index i is illegal (e.g. beyond the range of the string's length).
int main() {
	cout << "Please enter a line of text:\n";
	string userInput;
	getline(cin, userInput);
	string outputStr = userInput;
	//To find the index of the first non-space character in userInput
	int wordStart = findNextNonSpaceChar(userInput, 0);
	int wordEnd = wordStart;
	while (wordEnd <= userInput.length() - 1) {
		if (userInput.find(" ", wordStart) != string::npos) {
			//if there is a space after userInput[wordStart],
			//the wordEnd will be (index of the next space - 1)
			wordEnd = userInput.find(" ", wordStart) - 1;			
		}
		else {
			//if there is no space after wordStart,
			//then just take the index of the last char as wordEnd
			wordEnd = userInput.length() - 1;			
		}
		int wordLength = wordEnd - wordStart + 1;
		//To extract substring from userInput[wordStart] to userInput[wordEnd]
		string word = userInput.substr(wordStart, wordLength);
		if (isOnlyDigit(word)) {
			for (int j = wordStart; j <= wordEnd; j++) {
				outputStr[j] = SYMBOL;
			}
		}
		wordStart = findNextNonSpaceChar(userInput, wordEnd + 1);
		//The function will return -1 if wordEnd+1 is illegal
		//or the characters after that are all spaces
		if (wordStart == -1) {
			break;
		}
		wordEnd = wordStart;
	}
	cout << outputStr << endl;	
	return 0;
}
int findNextNonSpaceChar(string str, int i) {
	while (str[i] == ' ' && i < str.length()) {
		i++;
	}
	if (i < str.length()) {
		return i;
	}
	else {
		return -1;
	}
}

bool isOnlyDigit(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] < '0' || str[i] > '9') {
			return false;
		}
	}
	return true;
}
