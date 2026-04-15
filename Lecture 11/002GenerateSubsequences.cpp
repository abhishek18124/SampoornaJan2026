#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> arr = {10, 20, 30};
	int n = arr.size();

	// time : O(2^n.n)

	for (int num = 0; num < (1 << n); num++) {

		// generate the subset corresponding the 'num'

		cout << num << " : ";

		for (int k = 0; k < n; k++) {

			if ((num >> k) & 1) {
				cout << arr[k] << " ";
			}

		}

		cout << endl;

	}

	return 0;
}