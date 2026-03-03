#include <iostream>
#include <vector>
using namespace std;

// normal recursion => O(2^n)
int climbStairsRec(int n) { 
    if(n == 0 || n == 1) { //base case
        return 1;
    }

    return climbStairsRec(n-1) + climbStairsRec(n-2);
}

// DP approach (memoization) => O(n)
int climbStairsMemo(int n, vector<int>& dp) {
    if(n == 0 || n == 1) { //base case
        return 1;
    }

    if(dp[n] != -1) {
        return dp[n];
    }

    dp[n] = climbStairsMemo(n-1, dp) + climbStairsMemo(n-2, dp);
    return dp[n];
}

// DP approach (tabulation) => O(n)
int climbStairsTab(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n]; //ans on last idx
}


int main() {
    int n = 5;
    vector<int> dp(n+1, -1);
    
    cout << "no. of ways to climb " << n << " stairs = " << climbStairsRec(n) << endl;
    cout << "no. of ways to climb " << n << " stairs = " << climbStairsMemo(n, dp) << endl;
    cout << "no. of ways to climb " << n << " stairs = " << climbStairsTab(n) << endl;

    return 0;
}