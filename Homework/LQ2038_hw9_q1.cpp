//Homework 9 Question 1
//Assume that the input consists entirely of letters, whitespace, commas, and periods.
#include <iostream>
#include <string>
using namespace std;
const int TYPE_OF_LETTERS = 26;
//To represent 26 letters in English alphabet.
//Upper and lowercase versions of a letter are considered as the same letter.
bool isLetter(char ch);
string makeLowercase(string str);
int wordCount(string str);
void letterCountInArray(string str, int letterCount[]);
//letterCount is an array storing number of each letter appearing
//in the given string parameter str, i.e.
//letterCount[0] = number of "a" in str
//letterCount[1] = number of "b" in str
//...
//letterCount[25] = number of "z" in str
//Before calling this function, uppercase in str needs to be 
//converted to lowercase by function "makeLowercase"
int main() {
	cout << "Please enter a line of text:\n";
	string userInput;
	getline(cin, userInput);
	int numOfWords = wordCount(userInput);
	cout << numOfWords <<'\t'<<"words\n";
	string str = makeLowercase(userInput);
	int letterCount[TYPE_OF_LETTERS] = { 0 };
	letterCountInArray(str, letterCount);
	for (int i = 0; i < TYPE_OF_LETTERS; i++) {
		if (letterCount[i] > 0) {
			char letter = 'a' + i;
			cout << letterCount[i] << '\t' << letter << endl;
		}
	}	
	return 0;
}

int wordCount(string str) {
	int res = 0;
	if (isLetter(str[0])) {
		res = 1;
	}
	for (int i = 0; i < str.length() - 1; i++) {
		if (isLetter(str[i]) == false && isLetter(str[i+1]) == true) {
			res++;
		}
	}
	return res;
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