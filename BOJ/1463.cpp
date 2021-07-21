// 2021-07-21
// 1로 만들기
// https://www.acmicpc.net/problem/1463

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> dp(n+1);
    dp[1] = 0;

    for(int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] + 1;
        if(i % 2 == 0) dp[i] = min(dp[i], dp[i/2] + 1);
        if(i % 3 == 0) dp[i] = min(dp[i], dp[i/3] + 1);
    }
    cout << dp[n] << endl;

    return 0;
}