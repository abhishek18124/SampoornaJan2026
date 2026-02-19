class Solution {
public:

    bool f(const vector<int>& bloomDay, int m, int k, int timeLimit) {
        // check if you can make m bouquets of k adjacent flowers within the timelimit i.e. mid no. of days
        int cnt = 0;
        for (int day : bloomDay) {
            if (day <= timeLimit) {
                // current flower has bloomed so we can pick it
                cnt++;
                if (cnt == k) { // we've managed to make a bouquet of k adj. flowers
                    m--;
                    if (m == 0) { // we've managed to make m bouquets so we are done
                        return true;
                    }
                    cnt = 0;
                }
            } else {
                // current flower has not bloomed
                cnt = 0;
            }
        }

        // we didn't manage to make m bouquets in the given timeLimit

        return false;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int s = *min_element(bloomDay.begin(), bloomDay.end());
        int e = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while (s <= e) { // log(e-s) * n
            int mid = s + (e - s) / 2;
            if (f(bloomDay, m, k, mid)) {
                ans = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return ans;
    }
};