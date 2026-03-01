#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Node {
public:
    unordered_map<char, Node*> children;
    bool endOfWord;
    int freq;
    Node() {
        endOfWord = false;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string key) { //O(L)
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i]) == 0) { //check if key[i] already exists
                temp->children[key[i]] = new Node(); //insert newNode
                temp->children[key[i]]->freq = 1; 
            } else {
                temp->children[key[i]]->freq++; //update freq for existing letter in trie
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

    string getPrefix(string key) { //O(n*L)
        Node* temp = root;
        string prefix = "";

        for(int i=0; i<key.size(); i++) {
            prefix += key[i];

            if(temp->children[key[i]]->freq == 1) {
                break;
            }
            temp = temp->children[key[i]];
        }

        return prefix;
    }
};

string prefixProblem(vector<string>& dict) {
    Trie trie;
    for(int i=0; i<dict.size(); i++) {
        trie.insert(dict[i]);
    }

    for(int i=0; i<dict.size(); i++) {
        cout << trie.getPrefix(dict[i]) << endl;
    }
}

int main() {
    vector<string> dict = {"zebra", "dog", "duck", "dove", "done", "zoo"};

    prefixProblem(dict);

    return 0;
}