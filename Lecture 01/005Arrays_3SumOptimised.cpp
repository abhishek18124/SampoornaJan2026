class Solution {
public:

	// time : nlogn + n^2 ~ O(n^2)
	// space: logn due to sort(...)

	vector<vector<int>> threeSum(vector<int>& nums) {

		int n = nums.size();

		vector<vector<int>> ans;

		sort(nums.begin(), nums.end());

		for (int i = 0; i <= n - 3; i++) {

			if (i > 0 and nums[i] == nums[i - 1]) continue;

			// fix nums[i] as the 1st element of a potential
			// valid triplet and look for pair in nums[i+1...n-1]
			// whose sum is equal to -nums[i]

			int t = -nums[i];

			int j = i + 1;
			int k = n - 1;

			while (j < k) {

				int pairSum = nums[j] + nums[k];
				if (pairSum == t) {
					// you've found a valid triplet
					ans.push_back({nums[i], nums[j], nums[k]});
					j++;
					k--;
					while (j < k and nums[j] == nums[j - 1]) {
						j++;
					}
					while (j < k and nums[k] == nums[k + 1]) {
						k--;
					}

				} else if (pairSum > t) {
					k--;
				} else {
					// pairSum < t
					j++;
				}

			}

		}

		return ans;

	}
};