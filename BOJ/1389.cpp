// 2021-07-21
// 케빈 베이컨의 6단계 법칙
// https://www.acmicpc.net/problem/1389

#include <bits/stdc++.h>

using namespace std;

int bfs(int startVertex, vector<vector<int>>& graph, int n, vector<bool>& visited) {
    queue<int> q;
    q.push(startVertex);
    visited[startVertex] = true;

    int level = 0, ret = 0;
    while(!q.empty()) {
        int len = q.size();
        while(len--) {
            ret += level;

            int curr = q.front();
            q.pop();

            for(auto next: graph[curr]) {
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
            }
        }
        ++level;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n); // 인접 리스트
    for(int i = 0; i < m; ++i) {
        int from, to;
        cin >> from >> to;
        graph[from-1].push_back(to-1);
        graph[to-1].push_back(from-1);
    }

    int ans = 0, minVal = INT_MAX;
    for(int i = 0; i < n; ++i) {
        vector<bool> visited(n, false);
        int ret = bfs(i, graph, n, visited);
        if(minVal > ret) minVal = ret, ans = i+1;
    }

    cout << ans << endl;
    return 0;
}