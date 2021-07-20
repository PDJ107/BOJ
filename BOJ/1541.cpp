// 2021-01-05
// https://www.acmicpc.net/problem/1541

#include <bits/stdc++.h>
using namespace std;

vector<int> vals;
int result;

bool isnum(char c) {
    return !(c == '+' || c == '-');
}

int main() {
    string str;
    cin >> str;

    int num = 0;
    bool check = false;
    str = str + '+';
    for(int i = 0; i < str.size(); ++i) {
        if(!isnum(str[i])) {
            if(check) result -= num;
            else result += num;
            num = 0;
            if(str[i] == '-') check = true;
        }
        else {
            num = num * 10 + str[i] - '0';
        }
    }

    cout << result << endl;
    return 0;
}