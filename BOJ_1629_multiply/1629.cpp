#include <iostream>
using namespace std;

unsigned long long split(long a, long b, long c) {
    if(b <= 1) return a % c;

    unsigned long long temp{split(a, b/2, c)};
    
    if(b & 1) return temp * temp % c * a % c;
    else return temp * temp % c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long a, b, c;
    cin >> a >> b >> c;

    cout << split(a, b, c) << endl;

    return 0;
}