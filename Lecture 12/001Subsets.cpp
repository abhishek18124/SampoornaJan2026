// https://leetcode.com/problems/subsets/
class Solution {
public:

	void f(int i,
	       const vector<int>& nums,
	       vector<int>& subseq,
	       vector<vector<int>>& ans) {

		// base case
		if (i == nums.size()) {
			ans.push_back(subseq);
			return;
		}

		// recursive case

		// f(i) : take decisions for nums[i...n-1]

		// decide for nums[i]

		// option 1 : include nums[i] to subseq

		subseq.push_back(nums[i]);
		f(i + 1, nums, subseq, ans);
		subseq.pop_back(); // backtracking

		// option 2 : exclude nums[i] from subseq
		f(i + 1, nums, subseq, ans);

	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans; // to track all the subsequences
		vector<int> subseq; // to track a single subsequence
		f(0, nums, subseq, ans);
		return ans;
	}
};