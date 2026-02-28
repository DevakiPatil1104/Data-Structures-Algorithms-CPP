#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

unordered_set<int> getUnion(const vector<int>& arr1, const vector<int>& arr2) { //O(n+m) sizes of both arr
    unordered_set<int> s;

    for(int val: arr1) {
        s.insert(val);
    }

    for(int val: arr2) {
        s.insert(val);
    }

    return s;
}

vector<int> getIntersection(const vector<int>& arr1, const vector<int>& arr2) { //O(n+m)
    unordered_set<int> s;
    vector<int> ans;

    for(int val: arr1) {
        s.insert(val);
    }

    for(int val: arr2) {
        if(s.find(val) != s.end()) {
        ans.push_back(val);
        s.erase(val); //avoids duplicate
        }
    }

    return ans;
}

int main() {
    vector<int> arr1 = {7, 3, 9};
    vector<int> arr2 = {6, 3, 9, 2, 9, 4};
    
    return 0;
}