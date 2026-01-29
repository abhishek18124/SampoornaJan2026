#include<iostream>
#include<vector>

using namespace std;

int main() {

	int m, n;
	cin >> m >> n;

	vector<vector<int>> arr(m, vector<int>(n));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> psum(m, vector<int>(n)); // time : O(mn) // space : O(mn)
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			psum[i][j] = arr[i][j];
			if (i > 0) psum[i][j] += psum[i - 1][j]; // red box
			if (j > 0) psum[i][j] += psum[i][j - 1]; // dark blue box
			if (i > 0 and j > 0) psum[i][j] -= psum[i - 1][j - 1]; // light blue box
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << psum[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;


	return 0;
}