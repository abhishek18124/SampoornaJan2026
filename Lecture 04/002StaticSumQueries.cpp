#include<iostream>
#include<vector>
#define int long long

using namespace std;

int32_t main() {

	int n, q;
	cin >> n >> q;

	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	vector<int> psum(n);
	psum[0] = arr[0];

	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	while (q--) {
		int a, b;
		cin >> a >> b;
		a--; b--; // since we are following 0-based indexing
		int ans = a == 0 ? psum[b] : psum[b] - psum[a - 1];
		cout << ans << endl;
	}

	return 0;
}
