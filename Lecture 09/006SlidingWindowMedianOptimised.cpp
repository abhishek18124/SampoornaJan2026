class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        multiset<long long> left;
        multiset<long long> right;

        vector<double> ans;

        while (j < k) { // k.logk

            if (left.size() == right.size()) {
                left.insert(nums[j]);
            } else {
                right.insert(nums[j]);
            }

            j++;

            if (!right.empty() and * left.rbegin() > *right.begin()) {
                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }

        }

        if (k % 2 == 1) { // const
            // k is odd
            ans.push_back(*left.rbegin());
        } else {
            // k is even
            long long a = *left.rbegin();
            long long b = *right.begin();
            ans.push_back((a + b) / 2.0);
        }

        while (j < n) { // (n-k)*logk ~ O(nlogk)

            // slide the window

            if (nums[i] <= *left.rbegin()) {
                // remove nums[i] from left
                left.erase(left.find(nums[i]));
            } else {
                // remove nums[i] from right
                right.erase(right.find(nums[i]));
            }
            i++;
            if (left.size() <= right.size()) {
                left.insert(nums[j]);
            } else {
                right.insert(nums[j]);
            }

            if (!right.empty() and * left.rbegin() > *right.begin()) {
                left.insert(*right.begin());
                right.erase(right.begin());
                right.insert(*left.rbegin());
                left.erase(left.find(*left.rbegin()));
            }

            // update the ans

            if (k % 2 == 1) {
                // k is odd
                ans.push_back(*left.rbegin());
            } else {
                // k is even
                long long a = *left.rbegin();
                long long b = *right.begin();
                ans.push_back((a + b) / 2.0);
            }

            j++;

        }

        // time : O(nlogk)
        // space: O(k) due to left and right


        return ans;

    }
};