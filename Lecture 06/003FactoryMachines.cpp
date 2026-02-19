#include<iostream>
#include<vector>
#include<algorithm>
#define int long long

using namespace std;

bool f(int n, int t, const vector<int>& k, int timeLimit) {
    // can 'n' machines make 't' products in 'm' seconds ?
    int sum = 0;
    for (int ki : k) {
        sum += timeLimit / ki;
    }
    return sum >= t;
}

int32_t main() {

    int n, t;
    cin >> n >> t;

    vector<int> k(n);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }

    int s = *min_element(k.begin(), k.end());
    int e = s * t;

    int ans;

    while (s <= e) { // time : log(e-s) * n

        int m = s + (e - s) / 2;

        // can 'n' machines make 't' products in 'm' seconds ?

        if (f(n, t, k, m)) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }

    }

    cout << ans << endl;

    return 0;
}