#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();

	vector<int> psum(n);
	psum[0] = arr[0];

	for (int i = 1; i < n; i++) {
		psum[i] = psum[i - 1] + arr[i];
	}

	for (int i = 0; i < n; i++) {
		cout << psum[i] << " ";
	}

	cout << endl;

	return 0;
}