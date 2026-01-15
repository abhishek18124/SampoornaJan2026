#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {

	int n;
	cin >> n;

	vector<pair<int, int>> v;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		v.push_back({e, s});
	}

	sort(v.begin(), v.end());

	int cnt = 0;
	int lastMovieEndTime = 0;

	for (pair<int, int> p : v) {
		int e = p.first;
		int s = p.second;
		if (s >= lastMovieEndTime) {
			cnt++;
			lastMovieEndTime = e;
		}

	}

	cout << cnt << endl;

	return 0;
}