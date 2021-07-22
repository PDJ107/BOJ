// 2021-07-22
// 최소 힙
// https://www.acmicpc.net/problem/1927

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

class MinHeap {
private:
    int size;
    vector<int> heap;
public:
    MinHeap(int n): size{0}, heap(n) {}

    void push(int x) {
        int idx = size++;
        heap[idx] = x;

        // reheap Up
        while(idx > 0) {
            int next = (idx - 1) / 2;
            if(heap[next] > heap[idx]) swap(heap[next], heap[idx]);
            idx = next;
        }
    }
    int pop() {
        if(size == 0) return 0;
        int ret = heap[0], idx = 0;
        heap[0] = heap[--size];

        // reheap Down
        while(1) {
            int next = idx;
            int left = idx * 2 + 1;
            int right = idx * 2 + 2;

            if(left < size && heap[left] < heap[next]) next = left;
            if(right < size && heap[right] < heap[next]) next = right;
            if(next == idx) break;

            swap(heap[idx], heap[next]);
            idx = next;
        }
        return ret;
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    MinHeap heap(n);
    int cmd;
    for(int i = 0; i < n; ++i) {
        cin >> cmd;
        if(cmd == 0) cout << heap.pop() << endl;
        else heap.push(cmd);
    }

    return 0;
}