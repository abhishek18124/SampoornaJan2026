// https://cses.fi/problemset/task/1619

// difference array with coordinate compression

#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> l(n);

	set<int> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i] >> l[i];
		s.insert(a[i]);
		s.insert(l[i]);
	}

	map<int, int> cmpMap; // compression map
	int idx = 0;
	for (int x : s) {
		cmpMap[x] = idx;
		idx++;
	}

	vector<int> diff(idx, 0);
	for (int i = 0; i < n; i++) {
		diff[cmpMap[a[i]]] += 1;
		diff[cmpMap[l[i]]] -= 1;
	}

	for (int i = 1; i < idx; i++) {
		diff[i] += diff[i - 1];
	}

	cout << *max_element(diff.begin(), diff.end()) << endl;

	return 0;
}