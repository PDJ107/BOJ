#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map;
int cnt[3];

void split(int n, int y, int x) {
    bool done = true;
    for(int i = y; i < y+n; ++i) {
        for(int j = x; j < x+n; ++j) {
            if(map[i][j] != map[y][x]) {
                done = false;
                break;
            }
        }
        if(!done) break;
    }

    if(done) ++cnt[map[y][x]+1];
    else {
        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                split(n/3, y+(i*n/3), x+(j*n/3));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, temp;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        vector<int> vs;
        for(int j = 0; j < n; ++j) {
            cin >> temp;
            vs.push_back(temp);
        }
        map.push_back(vs);
    }

    split(n, 0, 0);

    cout << cnt[0] << endl;
    cout << cnt[1] << endl;
    cout << cnt[2] << endl;

    return 0;
}