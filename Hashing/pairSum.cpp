#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int arr[7] = {1, 2, 9, 11, 15, 5, 7};
    int n = 7;
    int target = 9;

    unordered_map<int, int> m;

    for(int i=0; i<n; i++) {
        int complement = target - arr[i];

        if(m.count(complement)) {
            cout << "ans = " << m[complement] << ", " << i << endl;
            break;
        }

        m[arr[i]] = i;
    }

    return 0;
}