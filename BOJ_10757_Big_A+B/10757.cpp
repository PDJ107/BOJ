// 2021-01-08
// https://www.acmicpc.net/problem/10757

#include <bits/stdc++.h>
using namespace std;

string a, b;
stack<char> result;

void solve(string a, string b) {
    int idxA = a.size() - 1;
    int idxB = b.size() - 1;
    int round = 0;
    while(idxA >= 0) {
        int num = a[idxA] - '0';
        if(idxB >= 0) num += b[idxB] - '0';
        result.push((num + round) % 10);
        round = (num + round) / 10;
        --idxA, --idxB;
    }
    if(round > 0) result.push(round);

    while(!result.empty()) {
        int num = result.top();
        result.pop();
        cout << num;
    }
}

int main() {
    cin >> a >> b;
    if(a.size() > b.size()) solve(a, b);
    else solve(b, a);
    return 0;
}