// 2021-07-22
// 이항 계수 3 (페르마의 소정리, 모듈러 역원)
// https://www.acmicpc.net/problem/11401

#include <bits/stdc++.h>
#define endl '\n'
#define MOD 1000000007

using namespace std;
using ll = long long;

ll fastPow(ll n, ll p, ll mod) {
    if(p == 0) return 1;
    else {
        ll val = fastPow(n, p/2, mod);
        if(p & 1) return (val * val) % mod * n % mod;
        else return (val * val) % mod;
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    cin >> n >> k;

    vector<ll> f(4000001);
    f[0] = f[1] = 1;
    for(int i = 2; i <= n; ++i) f[i] = i * f[i-1] % MOD;

    cout << f[n] * fastPow(f[k] * f[n-k] % MOD, MOD-2, MOD) % MOD << endl;

    return 0;
}