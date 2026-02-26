#include<iostream>
#define int long long

using namespace std;

bool f(int w, int h, int n, int m) {

	int r = m / h;
	int c = m / w;

	return r >= (n + (c - 1)) / c;

}

int32_t main() {

	int w, h, n;
	cin >> w >> h >> n;

	int s = max(w, h); // 1
	int e = max(w, h) * n; // 1e18

	int ans;

	while (s <= e) {

		int m = s + (e - s) / 2;

		if (f(w, h, n, m)) {
			ans = m;
			e = m - 1;
		} else {
			s = m + 1;
		}

	}

	cout << ans << endl;

	return 0;
}