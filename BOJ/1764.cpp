// 2021-07-22
// 듣보잡
// https://www.acmicpc.net/problem/1764

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    unordered_set<string> hashSet;
    string input_val;
    for(int i = 0; i < n; ++i) {
        cin >> input_val;
        hashSet.insert(input_val);
    }

    set<string> ans;
    for(int i = 0; i < m; ++i) {
        cin >> input_val;
        if(hashSet.find(input_val) != hashSet.end()) {
            ans.insert(input_val);
        }
    }

    cout << ans.size() << endl;
    for(auto s: ans) cout << s << endl;
    return 0;
}