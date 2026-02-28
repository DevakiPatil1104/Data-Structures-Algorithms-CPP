#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public:
    string key;
    int val;
    Node* next;

    Node(string key, int val) {
        this->key = key;
        this->val = val;
        next = NULL;
    }

    ~Node() {
        if(next != NULL) {
            delete next;
        }
    }
};

class HashTable {
    int tableSize;
    int currSize;
    Node** table;

    int HashFunc(string key) {
        int idx =0;
        for(int i=0; i<key.size(); i++) {
            idx += (key[i] * key[i]) % tableSize;
        }
        return idx % tableSize;
    }

    void rehash() {
        Node** oldTable = table;
        int oldSize = tableSize;

        tableSize = 2*tableSize;
        table = new Node*[tableSize];

        for(int i=0; i<tableSize; i++) {
            table[i] = NULL;
        }
        currSize = 0;
        //copy old values
        for(int i=0; i<oldSize; i++) {
            Node* temp = oldTable[i];
            while(temp != NULL) {
                insert(temp->key, temp->val);
                temp = temp->next;
            }
            
            if(oldTable[i] != NULL) {
                delete oldTable[i];
            }
        }
        delete[] oldTable;
    }

public:
    HashTable(int size) {
        tableSize = size;
        currSize = 0;

        table = new Node*[tableSize];

        for(int i=0; i<tableSize; i++) {
            table[i] = NULL;
        }
    }

    void insert(string key, int val) { //avg TC = O(1)
        int idx = HashFunc(key);

        Node* newNode = new Node(key, val);
        newNode->next = table[idx];
        table[idx] = newNode;

        currSize++;

        double lambda = currSize / (double)tableSize;
        if(lambda > 1) rehash(); //O(n) - worst case
    }

    int search(string key) {
        int idx = HashFunc(key);

        Node* temp = table[idx];
        while(temp != NULL) {
            if(temp->key == key) {
                return temp->val;
            } 
            temp = temp->next;
        }
        return -1;
    }

    void print() {
        for(int i=0; i<tableSize; i++) {
            cout << "idx " << i << " -> ";
            Node* temp = table[i];
            while(temp != NULL) {
                cout << "(" << temp->key << ", " << temp->val << ") -> ";
                temp = temp->next;
            }
            cout << endl;
        }
    }

    void remove(string key) {
        // find key
        int idx = HashFunc(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while(temp != NULL) {
            if(temp->key == key) {
                if(prev == temp) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                break;
            } 
            prev = temp;
            temp = temp->next;
        }
    }

};

int main() {
    HashTable ht(5);

    ht.insert("India", 150);
    ht.insert("China", 150);
    ht.insert("Nepal", 50);
    ht.insert("US", 100);

    ht.remove("China");
    ht.print();

    cout << "-------------\n";
    
    ht.remove("Nepal");
    ht.print();

    // cout << "India population = " << ht.search("India") << endl;
    // cout << "US population = " << ht.search("US") << endl;
    // cout << "Nepal population = " << ht.search("Nepal") << endl;

    return 0;
}