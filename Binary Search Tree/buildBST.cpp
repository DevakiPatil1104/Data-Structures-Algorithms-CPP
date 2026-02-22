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

void inorder(Node* root) {
    if(root == NULL) return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// search in node BST => O(height) ; avg => O(logn) ; worst => O(n)
bool search(Node* root, int key) { 
    if(root == NULL) return false; //BC

    if(root->data == key) { //FOUND
        return true;
    }

    if(root->data > key) {
        return search(root->left, key); //left subtree
    } else {
        return search(root->right, key); //right subtree
    }
}

int main() {
    // int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr2, 9);
    inorder(root);
    search(root, 3);
    return 0;
}