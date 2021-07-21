// 2021-07-21
// 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620

#include <bits/stdc++.h>

#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    unordered_map<string, string> hashMap;
    string val;
    for(int i = 0; i < n; ++i) {
        cin >> val;
        hashMap[val] = to_string(i+1);
        hashMap[to_string(i+1)] = val;
    }

    for(int i = 0; i < m; ++i) {
        cin >> val;
        cout << hashMap[val] << endl;
    }
    
    return 0;
}