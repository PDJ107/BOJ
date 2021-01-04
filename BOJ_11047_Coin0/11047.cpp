#include <bits/stdc++.h>
using namespace std;

int n, k, result;
vector<int> coins;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        int coin;
        cin >> coin;
        coins.push_back(coin);
    }
    
    for(int i = coins.size()-1; i >= 0 && k > 0; --i) {
        if(k >= coins[i]) {
            result += k / coins[i];
            k %= coins[i];   
        }
    }

    cout << result << endl;
    return 0;
}