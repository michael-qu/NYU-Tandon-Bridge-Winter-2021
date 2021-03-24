//Homework 8 Question 2
//To tell whether a given word is a palindrome.
//A palindrome is a word, which reads the same backward or forward.
//For example, noon, civic, radar, level, madam, and refer are all palindromes.
#include <iostream>
#include <string>
using namespace std;
string reverseString(string str);
bool isPalindrome(string str);
int main() {
	string strInput;
	cout << "Please enter a word: ";
	getline(cin, strInput);
	if (isPalindrome(strInput)) {
		cout << strInput << " is a palindrome";
	}
	else {
		cout << strInput << " is not a palindrome";
	}
	return 0;
}
string reverseString(string str) {
	string revStr = "";
	int n = str.length();
	for (int i = 0; i < n; i++) {
		revStr += str[n - 1 - i];
	}
	return revStr;
}
bool isPalindrome(string str) {
	return str==reverseString(str);
}