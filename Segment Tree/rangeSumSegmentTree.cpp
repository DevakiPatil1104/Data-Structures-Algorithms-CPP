#include <iostream>
#include <vector>
using namespace std;

class SegmentTree {
    vector<int> tree; //4*n
    int n;

    void buildTree(vector<int>& arr, int start, int end, int node) { //O(n)
        if(start == end) {
            tree[node] = arr[start];
            return;
        }

        int mid = start + (end-start)/2;

        buildTree(arr, start, mid, 2*node+1); //left
        buildTree(arr, mid+1, end, 2*node+2); //right

        tree[node] = tree[2*node+1] + tree[2*node+2];
    }

    int rangeSum(int qi, int qj, int si, int sj, int node) {

    }

public:
    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4*n);
        buildTree(arr, 0, n-1, 0);
    }

    void printTree() {
        for(int i=0; i<tree.size(); i++) {
            cout << tree[i] << " ";
        }
        cout << endl;
    }

    int rangeQuery(int qi, int qj) {
        return rangeSum(qi, qj, 0, n-1, 0);
    }

};

int main() {
    // range sum queries
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};

    SegmentTree st(arr);
    st.printTree();

    return 0;
}