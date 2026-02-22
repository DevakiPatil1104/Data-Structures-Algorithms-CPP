#include <iostream>
#include <vector>
using namespace std;

class Node {
public: 
    int data;
    Node* left;
    Node* right;
    Node(int data) {
        this->data = data;
        left = right = NULL;
    }
};

// build BST from sorted vector
Node* BSTfromSortedVec(vector<int> &arr, int st, int end) {
    if(st > end) return NULL; //BC

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = BSTfromSortedVec(arr, st, mid-1);
    curr->right = BSTfromSortedVec(arr, mid+1, end);

    return curr;
}

// get inorder seq
void getInorder(Node* root, vector<int>& nodes) {
    if(root == NULL) return;

    getInorder(root->left, nodes);
    nodes.push_back(root->data);
    getInorder(root->right, nodes);
}

Node* balancedBST(Node* root) {
    // 1. get inorder seq
    vector<int> nodes;
    getInorder(root, nodes);

    // 2. build BST from that seq
    root = BSTfromSortedVec(nodes, 0, nodes.size()-1);

    return root;
}


int main() {
    Node* root = new Node(6);
    root->left = new Node(5);
    root->left->left = new Node(4);
    root->left->left->left = new Node(3);

    root->right = new Node(7);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);

    root = balancedBST(root);

    return 0;
}