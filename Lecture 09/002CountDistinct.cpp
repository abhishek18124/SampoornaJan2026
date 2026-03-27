#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {

	vector<int> arr = {1, 2, 1, 3, 1, 4, 6, 4};
	int n = arr.size();
	int k = 3;

	vector<int> ans; // to track no. of distinct elements in each k-sized window

	int i = 0; // repr. the start of the window
	int j = 0; // repr. the end of the window

	map<int, int> winFreqMap;

	// 1. count no. of distinct elements in the 1st window

	while (j < k) { // k.logk
		winFreqMap[arr[j]]++;
		j++;
	}

	ans.push_back(winFreqMap.size());

	// 2. count no. of distinct elements in the remaining windows

	while (j < n) { // (n-k)(logk) ~ O(nlogk)
		// slide the window
		winFreqMap[arr[i]]--;
		if (winFreqMap[arr[i]] == 0) {
			winFreqMap.erase(arr[i]);
		}
		i++;
		winFreqMap[arr[j]]++;

		ans.push_back(winFreqMap.size());

		j++;
	}

	for (auto& x : ans) {
		cout << x << " ";
	}

	cout << endl;

	// time : O(nlogk)
	// space: O(k) due to winFreqMap

	return 0;
}