// 2021-07-22
// IOIOI
// https://www.acmicpc.net/problem/5525

// dp, 100점
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    string s;
    cin >> n >> m >> s;

    int ans = 0;
    vector<int> dp(m);
    dp[0] = s[0] == 'I' ? 1 : 0;
    dp[1] = s[1] == 'I' ? 1 : 0;

    for(int i = 2; i < m; ++i) {
        if(s[i] == 'I') {
            dp[i] = 1;
            if(s[i-2] == 'I' && s[i-1] == 'O') {
                dp[i] = dp[i-2] + 2;
                if(dp[i] >= n+n+1) ++ans;
            }
        }
        else dp[i] = 0;
    }

    cout << ans << endl;

    return 0;
}

/*
// 50점
#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    string s;
    cin >> n >> m >> s;

    string fs;
    for(int i = 0; i < n+n+1; ++i) {
        if(i & 1) fs.push_back('O');
        else fs.push_back('I');
    }

    int ans = 0, pos = s.find(fs, 0);
    while(pos != string::npos) {
        ++ans;
        pos = s.find(fs, pos + 1);
    }

    cout << ans << endl;

    return 0;
}*/