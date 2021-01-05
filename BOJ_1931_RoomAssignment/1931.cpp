// 2021-01-04
// https://www.acmicpc.net/problem/1931

#include <bits/stdc++.h>
using namespace std;

int n, result;
vector<pair<int,int>> t;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int s, e;
        cin >> s >> e;
        t.push_back({s, e});
    }

    sort(t.begin(), t.end());

    result = 1;
    int endtime = t[0].second;
    for(int i = 1; i < t.size(); ++i) {
        if(t[i].first < endtime) {
            if(t[i].second < endtime) {
                endtime = t[i].second;
            }
        }
        else {
            ++result;
            endtime = t[i].second;
        }
    }

    cout << result << endl;
    return 0;
}