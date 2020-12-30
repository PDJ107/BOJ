#include <iostream>
#include <vector>
using namespace std;

vector<vector<bool>> map;
vector<bool> vs;
int cnt[2];

void split(int n, int y, int x) {
    bool done = true;
    for(int i = y; i < y+n; ++i) {
        for(int j = x; j < x+n; ++j) {
            if(map[y][x] != map[i][j]) {
                done = false;
                break;
            }
        }
        if(!done) break;
    }
    if(done) ++cnt[map[y][x]];
    else {
        split(n/2, y, x);
        split(n/2, y, x+n/2);
        split(n/2, y+n/2, x);
        split(n/2, y+n/2, x+n/2);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vs.resize(n);
    for(int i = 0; i < n; ++i) {
        map.push_back(vs);
    }

    bool val;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> val;
            map[i][j] = val;
        }
    }
    split(n, 0, 0);

    cout << cnt[0] << endl;
    cout << cnt[1] << endl;

    return 0;
}