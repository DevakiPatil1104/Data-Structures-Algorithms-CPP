#include <iostream>
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
// print preorder seq of bst
void preorder(Node* root) {
    if(root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// build BST from sorted array
Node* buildBSTfromSortedArr(int arr[], int st, int end) {
    if(st > end) return NULL; //BC

    int mid = st + (end-st)/2;
    Node* curr = new Node(arr[mid]);

    curr->left = buildBSTfromSortedArr(arr, st, mid-1);
    curr->right = buildBSTfromSortedArr(arr, mid+1, end);

    return curr;
}


int main() {
    int arr[7] = {3, 4, 5, 6, 7, 8, 9};
    Node* root = buildBSTfromSortedArr(arr, 0, 6);
    preorder(root);
    return 0;
}