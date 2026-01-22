#include<iostream>
#include<vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n, k;
		cin >> n >> k;

		string s;
		cin >> s;

		vector<int> freq(26, 0);
		for (char ch : s) {
			freq[ch - 'a']++;
		}

		int oddCntr = 0; // to track no. of char. with odd frequencies
		for (int i = 0; i < 26; i++) {
			if (freq[i] % 2 == 1) {
				oddCntr++;
			}
		}

		if (oddCntr > k + 1) {
			cout << "NO" << endl; // we cannot build a palindrome from s after k deletions
		} else {
			cout << "YES" << endl; // we can build a palindrome from s after k deletions
		}

	}

	return 0;
}