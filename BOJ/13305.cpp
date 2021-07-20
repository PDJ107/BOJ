// 2021-01-05
// https://www.acmicpc.net/problem/13305

#include <bits/stdc++.h>
using namespace std;

int n;
long long result;
vector<int> costs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;
    costs.resize(n);
    for(int i = 0; i < n-1; ++i) 
        cin >> costs[i];

    int minDist = INT_MAX, dist;
    for(int i = 0; i < n-1; ++i) {
        cin >> dist;
        if(dist < minDist) minDist = dist;
        result += (long long)minDist * costs[i];
    }

    cout << result << endl;

    return 0;
}