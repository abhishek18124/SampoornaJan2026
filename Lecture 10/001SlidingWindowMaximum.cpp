// https://leetcode.com/problems/sliding-window-maximum/

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {

		int n = nums.size();

		int i = 0;
		int j = 0;

		deque<int> d;
		vector<int> ans;

		// time : O(n)
		// space: O(k) due to deque

		while (j < k) {
			while (!d.empty() and nums[j] > d.back()) {
				d.pop_back();
			}
			d.push_back(nums[j]);
			j++;
		}

		ans.push_back(d.front());

		while (j < n) {

			// slide the window

			if (nums[i] == d.front()) {
				d.pop_front();
			}
			i++;
			while (!d.empty() and nums[j] > d.back()) {
				d.pop_back();
			}
			d.push_back(nums[j]);

			ans.push_back(d.front());

			j++;

		}

		return ans;
	}
};