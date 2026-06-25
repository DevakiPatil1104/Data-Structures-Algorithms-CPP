#include<bits/stdc++.h>
using namespace std;

// Kadane's Algorithm (optimal approach) => TC = O(n)
int maxSubarraySum(int arr[], int n){
    int currSum = 0;
    int maxSum = INT_MIN;

    for(int i=0; i<n; i++){
        currSum += arr[i]; //running(prefix) sum
        maxSum = max(maxSum, currSum);

        if(currSum < 0){ // core idea
            currSum = 0;
        }
    }

    return maxSum;
}

int main() {
    int arr[6] = {2, -3, 6, -5, 4, 2};
    int n = sizeof(arr)/sizeof(int);

    int maxSum = maxSubarraySum(arr, n);
    cout << "maximum subarray sum = " << maxSum << endl;
    return 0;
}