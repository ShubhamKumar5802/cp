#include<bits/stdc++.h>
using namespace std;

int solve(map<pair<int, int>, int> &dp, vector<int> &wt, vector<int> &v, int n, int w) {
    if (n <= 0 || w <= 0) {
        return 0;
    }

    if (dp[make_pair(n, w)] != 0) return dp[make_pair(n, w)];

    if (wt[n - 1] <= w) {
        return dp[make_pair(n, w)] = max(solve(dp, wt, v, n - 1, w - wt[n - 1]) + v[n - 1], solve(dp, wt, v, n - 1, w));
    }
    else {
        return dp[make_pair(n, w)] = solve(dp, wt, v, n - 1, w);
    }


}
int main() {

    int n;
    cin >> n;

    int w;
    cin >> w;

    vector<int> wt(n);
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> v[i];
    }
    map<pair<int, int>, int> dp;
    cout << solve(dp, wt, v, n, w);

    return 0;
}