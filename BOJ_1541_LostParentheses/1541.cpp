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
    char sign = '+';
    str = str + '-';
    for(int i = 0; i < str.size(); ++i) {
        if(!isnum(str[i])) {
            if(sign == '+') {
                result += num;
                sign = str[i];
            }
            else {
                vals.push_back(num);
                if(str[i] == '-') {
                    int temp = 0;
                    for(int i = 0; i < vals.size(); ++i)
                        temp += vals[i];
                    result -= temp;
                    vals.clear();
                }
            }
            num = 0;
        }
        else {
            num = num * 10 + str[i] - '0';
        }
    }

    cout << result << endl;
    return 0;
}