#include<iostream>
#include<vector>
#define int long long

using namespace std;

bool f(int n, int x, vector<int>& a, int m) {
    // can we build a tank of height 'm'
    // s.t water consumptions is <= x units ?
    int sum = 0;
    for (int column_height : a) {
        sum = sum + max(0ll, m - column_height);
    }
    return sum <= x;

}

int32_t main() {

    int t;
    cin >> t;

    while (t--) {

        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int s = 1;
        int e = 2e9;

        int ans;

        while (s <= e) {

            int m = s + (e - s) / 2;

            // can we build a tank of height 'm'
            // s.t water consumptions is <= x units ?

            if (f(n, x, a, m)) {
                ans = m;
                s = m + 1;
            } else {
                e = m - 1;
            }

        }

        cout << ans << endl;

    }

    return 0;
}