#include<iostream>
#include<vector>

using namespace std;

int main() {

	// time : 2n + 26 ~ O(n)
	// space: 26 + 26 ~ O(1)

	string s = "aabbccc";
	string t = "aabbccd";

	// 1. build a freqMap for s[]

	vector<int> fs(26, 0);
	for (char ch : s) {
		int idx = ch - 'a';
		fs[idx]++;
	}

	// 2. build a freqMap for t[]

	vector<int> ft(26, 0);
	for (char ch : t) {
		int idx = ch - 'a';
		ft[idx]++;
	}

	for (int i = 0; i < 26; i++) {
		cout << fs[i] << " " << ft[i] << endl;
	}

	// 3. compare the two freqMaps

	bool flag = true; // assume s and t are anagrams

	for (int i = 0; i < 26; i++) {
		if (fs[i] != ft[i]) {
			flag = false;
			break;
		}
	}

	if (flag) {
		cout << "anagrams" << endl;
	} else {
		cout << "not anagrams" << endl;
	}

	return 0;
}