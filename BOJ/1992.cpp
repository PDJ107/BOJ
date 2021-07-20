#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> map;
string ans;

void quadTree(int n, int y, int x) {
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

    if(done) ans.push_back(map[y][x]);
    else {
        ans.push_back('(');

        quadTree(n/2, y, x);
        quadTree(n/2, y, x+n/2);
        quadTree(n/2, y+n/2, x);
        quadTree(n/2, y+n/2, x+n/2);

        ans.push_back(')');
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        string temp;

        cin >> temp;
        map.push_back(temp);
    }
    
    quadTree(n, 0, 0);

    cout << ans << endl;

    return 0;
}