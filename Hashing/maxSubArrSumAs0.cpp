#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns length of longest subarray with sum = 0

int maxSubArrSum0(vector<int>& arr) {
    unordered_map<int, int> mp; //sum, idx
    mp[0] = -1; //assume sum was zero before starting & handles subarrays starting at index 0
    int sum = 0, maxSubArr = 0;

    for(int j=0; j<arr.size(); j++) {
        sum += arr[j];

        if(mp.count(sum)) {
            int currSubArr = j - mp[sum]; //j-idx
            maxSubArr = max(maxSubArr, currSubArr);
        } else {
            mp[sum] = j; // store first occurrence only (to maximize length)
        }
    }

    return maxSubArr;
}

int main() {
    vector<int> arr = {15, -2, 2, -8, 1, 7, 10};

    cout << maxSubArrSum0(arr);

    return 0;
}