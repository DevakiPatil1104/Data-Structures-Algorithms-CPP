#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Returns count of subarrays with sum = k

int subArrCountWithSumK(vector<int>& arr, int k) { //O(n)
    unordered_map<int, int> mp; //sum, count
    mp[0] = 1; 
    int sum = 0, ans = 0;

    for(int j=0; j<arr.size(); j++) {
        sum += arr[j];

        if(mp.count(sum-k)) {
            ans += mp[sum-k];
        } 

        if(mp.count(sum)) {
            mp[sum]++;
        } else {
            mp[sum] = 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {10, 2, -2, -20, 10};
    int k = -10;

    cout << "Count of subarrays with sum = -10 is " << subArrCountWithSumK(arr, k);

    return 0;
}