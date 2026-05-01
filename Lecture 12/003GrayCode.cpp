// https://leetcode.com/problems/gray-code/
class Solution {
public:

	bool flag = false; // assume we are yet to generate n-bit gray code sequence

	void f(vector<int>& ans, int n, set<int>& s) {

		// base case
		if (ans.size() == (1 << n)) {
			flag = true;
			return;
		}

		// recursive case

		// decide the next element

		for (int i = 0; i < n; i++) {

			int prev = ans.back();
			int next = prev ^ (1 << i);
			if (s.find(next) != s.end()) {
				// next is already present in ans
				continue;
			}
			ans.push_back(next);
			s.insert(next);

			f(ans, n, s);

			if (flag) {
				// we've managed to build n-bit gray code sequence
				return;
			}

			ans.pop_back();
			s.erase(next);

		}

	}

	vector<int> grayCode(int n) {
		vector<int> ans;
		set<int> s; s.insert(0);
		ans.push_back(0);
		f(ans, n, s);
		return ans;
	}
};