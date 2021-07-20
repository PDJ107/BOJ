// 2021-07-20
// https://www.acmicpc.net/problem/1107

#include <bits/stdc++.h>
using namespace std;

int checkNum(int num, vector<bool>& broken) {
    int len = 0;
    while(1) {
        if(broken[num % 10]) return -1;
        num /= 10, ++len;
        if(num == 0) break;
    }
    return len;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, val;
    cin >> n >> m;
    vector<bool> broken(10);
    for(int i = 0; i < m; ++i) {
        cin >> val;
        broken[val] = true;
    }

    int ans = abs(n-100);
    for(int i = 0; i <= 1000000; ++i) {
        int len = checkNum(i, broken);
        if(len > 0 && ans > abs(n-i) + len) {
            ans = abs(n-i) + len;
        }
    }

    cout << ans << endl;

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

void findChannel(int depth, int len, int n, vector<int>& bt, int num, pair<int,int>& ans) {
    if(depth > len) return;
    else {
        for(auto i: bt) {
            num = num - (num % 10) + i;
            int diff = abs(n-num) + depth + 1;
            if(ans.first > diff) ans = {diff, num};
            findChannel(depth+1, len, n, bt, num*10, ans);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, val;
    cin >> n >> m;
    unordered_set<int> broken_bt;
    vector<int> bt;
    for(int i = 0; i < m; ++i) {
        cin >> val;
        broken_bt.insert(val);
    }

    for(int i = 0; i < 10; ++i) {
        if(broken_bt.find(i) != broken_bt.end()) continue;
        bt.push_back(i);
    }

    int len = 0, tn = n;
    while(tn) ++len, tn /= 10;
    
    pair<int,int> ans = {INT_MAX, INT_MAX};
    findChannel(0, len, n, bt, 0, ans);

    ans.first = min(ans.first, abs(n-100));
    cout << ans.first << endl;

    return 0;
}*/