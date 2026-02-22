#include <iostream>
#include <vector>
using namespace std;

class Heap {
    vector<int> vec; //max Heap (CBT)

public:
    void push(int val) {
        // step 1: insert
        vec.push_back(val); //O(1)

        // step 2: fix heap
        int x = vec.size()-1; //childIdx
        int parI = (x-1)/2; //parentIdx

        while(parI >= 0 && vec[x] > vec[parI]) { //O(logn)
            swap(vec[x], vec[parI]);
            x = parI;
            parI = (x-1)/2;
        }
    }

    void heapify(int i) { //i = parIdx
        if(i >= vec.size()) {
            return;
        }

        int l = 2*i+1;
        int r = 2*i+2;

        int maxIdx = i;
        if(l < vec.size() && vec[l] > vec[maxIdx]) {
            maxIdx = l;
        }
        if(r < vec.size() && vec[r] > vec[maxIdx]) {
            maxIdx = r;
        }

        swap(vec[i], vec[maxIdx]);
        if(maxIdx != i) {
        heapify(maxIdx);
        }
    }

    void pop() {
        // step 1: swap(root, latIdx) O(1)
        swap(vec[0], vec[vec.size()-1]);

        // step 2: delete lastIdx O(1)
        vec.pop_back();

        // step 3: heapify O(logn)
        heapify(0);
    }

    int top() {
        return vec[0]; // highest priority element
    }

    bool empty() {
        return vec.size() == 0;
    }
};

int main() {
    Heap heap;
    heap.push(9);
    heap.push(4);
    heap.push(8);
    heap.push(1);
    heap.push(2);
    heap.push(5);

    while(!heap.empty()) {
    cout << "top = " << heap.top() << endl;
    heap.pop();
    }

    return 0;
}