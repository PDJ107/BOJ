// 2021-07-21
// 팩토리얼 0의 개수
// https://www.acmicpc.net/problem/1676

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cnt2 = 0, cnt5 = 0;

    for(int i = 1; i <= n; ++i) {
        int num = i;
        while(num) {
            if(num % 2 == 0) num /= 2, ++cnt2;
            else if(num % 5 == 0) num /= 5, ++cnt5;
            else break;
        }
    }
    cout << min(cnt2, cnt5) << endl;
    return 0;
}