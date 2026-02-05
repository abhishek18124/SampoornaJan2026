/*

input:

6
120 30 77 12 8 12 77

output:

0 1 1 2 3 3 4

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	// set<int> s;
	// for(int x : v) {
	// 	s.insert(x);
	// }

	set<int> s(v.begin(), v.end());

	map<int, int> cmpMap;
	int idx = 0;
	for (int num : s) {
		cmpMap[num] = idx;
		idx++;
	}

	for (auto [val, cmp_val] : cmpMap) {
		cout << val << " " << cmp_val << endl;
	}

	return 0;

}