//Homework 9 Question 2
/*
To determine whether two given strings are anagrams.
Two strings are anagrams if the letters can be rearranged to form each other.
For example, “Eleven plus two” is an anagram of “Twelve plus one”.
Each string contains one ‘v’, three ‘e’s, two ‘l’s, etc.
The program is not case sensitive and punctuation/spaces are disregarded.
*/
#include <iostream>
#include <string>
using namespace std;
const int TYPE_OF_LETTERS = 26;
//To represent 26 letters in English alphabet.
//Upper and lowercase versions of a letter are considered as the same letter.
bool isLetter(char ch);
string makeLowercase(string str);
void letterCountInArray(string str, int letterCount[]);
bool isAnagram(string str1, string str2);
int main() {
	string userInput1, userInput2, str1, str2;
	cout << "Please enter the first one-line string:\n";
	getline(cin, userInput1);
	str1 = makeLowercase(userInput1);
	cout << "Please enter the second one-line string:\n";
	getline(cin, userInput2);
	str2 = makeLowercase(userInput2);
	if (isAnagram(str1, str2)) {
		cout << '\"' << userInput1 << "\" and \"" << userInput2 << "\" are anagrams.\n";
	}
	else {
		cout << '\"' << userInput1 << "\" and \"" << userInput2 << "\" are not anagrams.\n";
	}
	return 0;
}
bool isAnagram(string str1, string str2) {
	int letterCount1[TYPE_OF_LETTERS] = { 0 };
	int letterCount2[TYPE_OF_LETTERS] = { 0 };
	letterCountInArray(str1, letterCount1);
	letterCountInArray(str2, letterCount2);
	for (int i = 0; i < TYPE_OF_LETTERS; i++) {
		if (letterCount1[i] != letterCount2[i]) {
			return false;
		}
	}
	return true;
}

void letterCountInArray(string str, int letterCount[]) {
	for (int i = 0; i < str.length(); i++) {
		if (isLetter(str[i])) {
			letterCount[(str[i] - 'a')]++;
		}
	}
}

string makeLowercase(string str) {
	for (int i = 0; i < str.length(); i++) {
		//It would be quite straightforward if we just use
		//tolower function defined in <cctype> library, i.e.
		//str[i] = tolower(str[i]);
		//For practice purpose, I just code this function by myself.
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] = 'a' + (str[i] - 'A');
		}
	}
	return str;
}

bool isLetter(char ch) {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return true;
	}
	else {
		return false;
	}
}