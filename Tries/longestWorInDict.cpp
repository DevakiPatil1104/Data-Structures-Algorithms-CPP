#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

class Node {
public:
    map<char, Node*> children;
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

    void longestWordHelper(Node* root, string &ans, string temp) {
        for(pair<char, Node*> child: root->children) {
            if(child.second->endOfWord) { //if EOW is true
                temp += child.first; //add char to temp

                if((temp.size() == ans.size() && temp < ans) || (temp.size() > ans.size())) {
                    ans = temp;
                }

                longestWordHelper(child.second, ans, temp);
                temp = temp.substr(0, temp.size()-1);
            }
        }
    }

    string longestWord() {
        string ans = "";
        longestWordHelper(root, ans, "");
        return ans;
    }
};

string longestWord(vector<string>& words) {
    Trie trie;
    for(string word: words) {
        trie.insert(word);
    }

    return trie.longestWord();
}

int main() {
    vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    cout << longestWord(words) << endl;

    return 0;
}