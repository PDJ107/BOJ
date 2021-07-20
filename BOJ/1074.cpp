// 2021-07-20
// https://www.acmicpc.net/problem/1074

#include <bits/stdc++.h>
using namespace std;

int findNum(int n, int r, int c) {
    if(n == 1) return 0;
    else {
        if(r < n/2 && c < n/2) 
            return findNum(n/2, r, c);
        else if(r < n/2 && c >= n/2)
            return findNum(n/2, r, c-(n/2)) + pow(n/2, 2);
        else if(r >= n/2 && c < n/2) 
            return findNum(n/2, r-(n/2), c) + pow(n/2, 2) * 2;
        else 
            return findNum(n/2, r-(n/2), c-(n/2)) + pow(n/2, 2) * 3;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;
    
    cout << findNum(pow(2, n), r, c) << endl;

    return 0;
}