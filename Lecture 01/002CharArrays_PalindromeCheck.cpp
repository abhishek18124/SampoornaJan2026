#include<iostream>
#include<string>

using namespace std;

// time : n/2.const ~ O(n)
// space: O(1)

bool isPalindrome(string& str) {

	int i = 0;
	int j = str.size() - 1;

	while (i < j) {
		if (str[i] == str[j]) {
			i++;
			j--;
		} else {
			// str is not a palindrome
			return false;
		}
	}

	// str is a palindrome

	return true;

}

int main() {

	string str = "abca";

	if (isPalindrome(str)) {
		cout << str << " is a palindrome" << endl;
	} else {
		cout << str << " is not a palindrome" << endl;
	}

	return 0;
}