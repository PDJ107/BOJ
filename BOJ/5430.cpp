// 2021-07-22
// AC
// https://www.acmicpc.net/problem/5430

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        string cmd, arr;
        cin >> cmd >> n >> arr;

        deque<int> dq;
        int idx = 1;
        for(int i = 0; i < n; ++i) {
            int num = 0;
            while(arr[idx] != ',' && arr[idx] != ']') {
                num = num * 10 + (arr[idx]-'0');
                ++idx;
            }
            ++idx;
            dq.push_back(num);
        }

        bool reverse = false, error = false;
        for(int i = 0; i < cmd.size() && !error; ++i) {
            if(cmd[i] == 'R') reverse = (reverse + 1) % 2;
            else {
                if(dq.empty()) error = true;
                else if(reverse) dq.pop_back();
                else dq.pop_front();
            }
        }

        if(error) cout << "error" << endl;
        else {
            cout << '[';
            int len = dq.size();
            for(int i = 0; i < len; ++i) {
                if(reverse) {
                    cout << dq.back();
                    dq.pop_back();
                }
                else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if(dq.size() > 0) cout << ',';
            }
            cout << ']' << endl;
        }

    }

    return 0;
}