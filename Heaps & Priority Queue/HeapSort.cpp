#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void heapify(int i, vector<int> &vec, int n) { //O(logn)
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int maxIdx = i;

    if(left < n && vec[left] > vec[maxIdx]) {
        maxIdx = left;
    }
    if(right < n && vec[right] > vec[maxIdx]) {
        maxIdx = right;
    }
    if(maxIdx != i) {
        swap(vec[i], vec[maxIdx]);
        heapify(maxIdx, vec, n);
    }
}

void heapSort(vector<int> &vec) {
    int n = vec.size();

    // step1: build maxHeap
    for(int i = (n/2)-1; i>=0; i--) { //O(n * logn)
        heapify(i, vec, n);
    }

    // step2: taking elements to correct position
    for(int i=n-1; i>=0; i--) { //O(n * logn)
        swap(vec[0], vec[i]);
        heapify(0, vec, i);
    }
}

int main() {
    vector<int> vec = {9, 4, 8, 1, 2, 5};

    heapSort(vec);

    for(int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    return 0;
}