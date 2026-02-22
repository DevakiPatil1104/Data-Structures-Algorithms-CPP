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
// build BST
Node* insert(Node* root, int val) { 
    if(root == NULL) {
        root = new Node(val);
        return root;
    }
    if(root->data > val) { //left subtree
        root->left = insert(root->left, val);
    } else { //right subtree
        root->right = insert(root->right, val);
    }
    return root;
}
Node* buildBST(int arr[], int n) {
    Node* root = NULL;
    for(int i=0; i<n; i++) {
        root = insert(root, arr[i]);
    }
    return root;
}
// print inorder seq of bst
void inorder(Node* root) {
    if(root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}



void printInRange(Node* root, int start, int end) {
    if(root == NULL) return;

    // case 1: root in range => call both sides
    if(start <= root->data && root->data <= end) { 
        printInRange(root->left, start, end); //inorder
        cout << root->data << " ";
        printInRange(root->right, start, end);
    }

    // case 2: root smaller than range => call only right subtree
    else if(root->data < start) {
        printInRange(root->right, start, end);
    }

    // case 3: root greater than range => call only left subtree
    // if(root->data > end) {
    else {
        printInRange(root->left, start, end);
    }

    return;
}

int main() {
    // int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr2, 9);
    
    printInRange(root, 5, 12);
    

    
    return 0;
}