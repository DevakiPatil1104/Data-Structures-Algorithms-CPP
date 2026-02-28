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
};

bool helper(Trie &trie, string key) {
    if(key.size() == 0) return true; //(BC) empty str as exists in dict

    for(int i=0; i<key.size(); i++) {
        string first = key.substr(0, i+1);
        string second = key.substr(i+1);

        if(trie.search(first) && helper(trie, second)) { //if first=true -> go for second
            return true;
        }
    }

    return false;
}

bool wordBreak(vector<string>& dict, string key) {
    Trie trie;
    for(string word: dict) {
        trie.insert(word);
    }
     
    return helper(trie, key);
}

int main() {
    vector<string> dict = {"i", "like", "sam", "samsung", "mobile", "ice"};

    cout << wordBreak(dict, "ilikesamsung") << endl; //1->true
    cout << wordBreak(dict, "ilikesung") << endl; //0->false sung not in dict
    cout << wordBreak(dict, "ilikesam") << endl; //1->true

    return 0;
}