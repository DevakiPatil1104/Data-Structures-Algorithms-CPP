#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Catalan's number calculation:

// Recursive Approach => O(2^n)
int recCat(int n) {
    if(n == 0 || n == 1) return 1; //base case (smallest catalan no.)

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += recCat(i) * recCat(n-i-1);
    }

    return ans;

}

// Memoization (DP) Approach => O(n^2)
int memoCat(int n, vector<int>& dp) {
    if(n == 0 || n == 1) return 1; //base case (smallest catalan no.)

    if(dp[n] != -1) return dp[n];

    int ans = 0;
    for(int i=0; i<n; i++) {
        ans += memoCat(i, dp) * memoCat(n-i-1, dp);
    }

    return dp[n] = ans;

}

// Tabulation (DP) approach => O(n^2)
int tabCat(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<i; j++) {
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    return dp[n];
}


int main() {
    int n = 4;

    cout << recCat(n) << endl;

    vector<int> dp(n+1, -1);
    cout << memoCat(n, dp) << endl;

    cout << tabCat(n) << endl;
    
    return 0;
}