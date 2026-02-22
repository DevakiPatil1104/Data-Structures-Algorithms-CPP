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


Node* getInorderSuccessor(Node* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root; //IS
}

Node* delNode(Node* root, int val) {
    if(root == NULL) return NULL;

    if(val < root->data) {
        root->left = delNode(root->left, val);
    } else if (val > root->data) {
        root->right = delNode(root->right, val);
    } else { //root==val
        // case 1: 0 child (leaf node)
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // case 2: 1 child (left or right)
        if(root->left == NULL || root->right == NULL) {
            // if(root->left != NULL) { //left child valid
            //     delete root;
            //     return root->left;
            // } else { //right child valid
            //     delete root;
            //     return root->right;
            // }
            Node* child = (root->left != NULL) ? root->left : root->right;
            delete root;
            return child;
        }
        
        // case 3: 2 children
        Node* IS = getInorderSuccessor(root->right);
        root->data = IS->data;
        root->right = delNode(root->right, IS->data); //case1, case2
        return root;
    }
    return root;
}


int main() {
    // int arr[6] = {5, 1, 3, 4, 2, 7};
    int arr2[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

    Node* root = buildBST(arr2, 9);
    inorder(root);
    cout << endl;

    delNode(root, 4);
    inorder(root);
    cout << endl;

    delNode(root, 10);
    inorder(root);
    cout << endl;

    delNode(root, 5);
    inorder(root);
    cout << endl;

    
    return 0;
}