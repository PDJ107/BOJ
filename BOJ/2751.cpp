// 2021-07-21
// 수 정렬하기 2
// https://www.acmicpc.net/status?from_problem=1&problem_id=2751

#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

// quicksort 352 ms, 5932 KB
// s가 피봇일 시 시간초과
void quicksort(vector<int>& arr, int start, int end) {
    if(start >= end-1) return;
    else {
        int pivot = rand() % (end-start) + start;
        swap(arr[start], arr[pivot]);
        
        int chg = start + 1;
        for(int i = start+1; i < end; ++i) {
            if(arr[i] < arr[start]) {
                swap(arr[i], arr[chg++]);
            }
        }
        swap(arr[start], arr[chg-1]);

        quicksort(arr, start, chg);
        quicksort(arr, chg, end);
    }
}

// mergesort 384 ms, 11908 KB
void merge(vector<int>& arr, int start, int end) {
    int mid = (end-start) / 2 + start;
    vector<int> tmp(end-start);

    int left = start, right = mid;
    for(int i = 0; i < end-start; ++i) {
        if(left < mid && right < end) {
            tmp[i] = arr[left] < arr[right] ? arr[left++] : arr[right++];
        }
        else {
            tmp[i] = left < mid ? arr[left++] : arr[right++];
        }
    }

    for(int i = start; i < end; ++i) arr[i] = tmp[i-start];
}

void mergesort(vector<int>& arr, int start, int end) {
    if(start >= end-1) return;
    else {
        int mid = (end-start) / 2 + start;
        mergesort(arr, start, mid);
        mergesort(arr, mid, end);
        merge(arr, start, end);
    }
}

// heapsort 396 ms, 9836 KB
void reheapUp(vector<int>& heap, int size) {
    int idx = size-1;
    while(idx > 0) {
        int next = (idx - 1) / 2;
        if(heap[next] > heap[idx]) swap(heap[next], heap[idx]);
        idx = next;
    }
}

void reheapDown(vector<int>& heap, int size) {
    int idx = 0;
    heap[0] = heap[size];
    while(1) {
        int next = idx;
        int left = idx * 2 + 1;
        int right = idx * 2 + 2;

        if(left < size && heap[left] < heap[next]) next = left;
        if(right < size && heap[right] < heap[next]) next = right;

        if(next == idx) return;

        swap(heap[idx], heap[next]);
        idx = next;
    }
}

void heapsort(vector<int>& arr, int n) {
    int size = 0;
    vector<int> minHeap(n);

    // push
    for(int i = 0; i < n; ++i) {
        minHeap[i] = arr[i];
        reheapUp(minHeap, ++size);
    }

    // pop
    for(int i = 0; i < n; ++i) {
        cout << minHeap[0] << endl;
        reheapDown(minHeap, --size);
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //srand((unsigned int)time(NULL));

    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; ++i) cin >> arr[i];

    //quicksort(arr, 0, n);    
    //mergesort(arr, 0, n);    

    //for(int i = 0; i < n; ++i) cout << arr[i] << endl;

    heapsort(arr, n);

    return 0;
}