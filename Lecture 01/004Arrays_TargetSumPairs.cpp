#include<iostream>
#include<vector>

using namespace std;

int main() {

	vector<int> v = {10, 20, 30, 40, 50, 60};
	int t = 60;

	int i = 0;
	int j =  v.size() - 1;
	int cntr = 0;

	// time : O(n)
	// space: O(1)

	while ( i < j) {
		int pairSum = v[i] + v[j];
		if (pairSum == t) {
			cntr++;
			i++;
			j--;
		} else {
			if (pairSum > t) {
				j--;
			} else {
				// pairSum < t
				i++;
			}
		}
	}

	cout << cntr << endl;

	return 0;
}