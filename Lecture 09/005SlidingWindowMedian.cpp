class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {

        vector<double> ans;

        multiset<long long> ms;

        int i = 0;
        int j = 0;

        while (j < k) { // k.logk
            ms.insert(nums[j]);
            j++;
        }

        if (k % 2 == 1) { // k/2
            // k is odd
            auto it = ms.begin();
            for (int x = 0; x < k / 2; x++) {
                it++;
            }
            ans.push_back(*it);
        } else {
            // k is even
            auto it = ms.begin();
            for (int x = 1 ; x < k / 2; x++) {
                it++;
            }
            long long a = *it;
            it++;
            long long b = *it;
            ans.push_back((a + b) / 2.0);
        }

        while (j < n) { // (n-k)(logk + k + c) ~ n.logk + nk + n.c - klogk - k^2 - k

            // slide the window

            ms.erase(ms.find(nums[i]));
            i++;
            ms.insert(nums[j]);

            if (k % 2 == 1) {
                // k is odd
                auto it = ms.begin();
                for (int x = 0; x < k / 2; x++) {
                    it++;
                }
                ans.push_back(*it);
            } else {
                // k is even
                auto it = ms.begin();
                for (int x = 1 ; x < k / 2; x++) {
                    it++;
                }
                long long a = *it;
                it++;
                long long b = *it;
                ans.push_back((a + b) / 2.0);
            }

            j++;

        }

        // time : O(nk)
        // space: O(k) due to multset<>

        return ans;

    }
};