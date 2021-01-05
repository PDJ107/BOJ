// 2021-01-04
// https://www.acmicpc.net/problem/11399

#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<int> t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int time;
        cin >> time;
        t.push_back(time);
    }

    sort(t.begin(), t.end());

    result = t[0];
    for(int i = 1; i < n; ++i) {
        t[i] += t[i-1];
        result += t[i];

        // result += t[i] * (n-i)
    }

    cout << result << endl;
    return 0;
}