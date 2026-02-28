#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }

    void insert(string key) { //O(L)
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) { //check if key[i] already exists
                temp->children[key[i]] = new Node(); //insert newNode
            }
            temp = temp->children[key[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string key) { //O(L)
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {
                temp = temp->children[key[i]];
            } else {
                return false;
            }
        }
        return (temp->endOfWord);
    }

    bool startsWith(string prefix) {
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++) {
            if(temp->children.count(prefix[i])) {
                temp = temp->children[prefix[i]];
            } else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<string> words = {"apple", "app", "sam", "mango", "man", "woman"};
    Trie trie;

    for(string word: words) {
        trie.insert(word);
    }

    cout << trie.startsWith("moon") << endl;

    return 0;
}