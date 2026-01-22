#include<iostream>
#include<vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {

		string s;
		cin >> s;

		vector<bool> working(26, false);

		for (int i = 0; i < s.size(); ) {

			int j;
			for (j = i + 1; j < s.size() and s[j] == s[i]; j++);
			if ((j - i) % 2 == 1) {
				// button corr. to s[i] is working
				working[s[i] - 'a'] = true;
			}
			i = j;

		}

		for (int i = 0; i < 26; i++) {
			if (working[i]) {
				cout << (char)(i + 'a');
			}
		}

		cout << endl;

	}

	return 0;

}