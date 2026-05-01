// https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/
class Solution {
public:
	int maxSoFar = 0; // to track maximum no. of requests that can be accepted
	int cnt = 0; // to track no. of requests accepted so far

	void f(int i, vector<int>& netMov, const vector<vector<int>>& requests) {

		// base case
		if (i == requests.size()) {
			// check the validity of your decisions
			bool flag = true; // assume all your decisions were valid
			for (int i = 0; i < netMov.size(); i++) {
				if (netMov[i] != 0) {
					flag = false;
					break;
				}
			}
			if (flag) {
				maxSoFar = max(maxSoFar, cnt);
			}
			return;
		}

		// recursive case

		// decide for requests[i]

		int from_i = requests[i][0];
		int to_i = requests[i][1];

		// option 1 : accept the ith request

		cnt++;
		netMov[from_i]--;
		netMov[to_i]++;

		f(i + 1, netMov, requests);

		cnt--;
		netMov[from_i]++;
		netMov[to_i]--;

		// option 2 : reject the ith request

		f(i + 1, netMov, requests);

	}

	int maximumRequests(int n, vector<vector<int>>& requests) {
		vector<int> netMov(n, 0);
		f(0, netMov, requests);
		return maxSoFar;
	}
};