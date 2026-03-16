#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Count structurally unique BSTs which can be formed from n nodes: O(n^2)
// Catalan variation

int numTrees(int n) {
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

    cout << numTrees(n) << endl;
    
    return 0;
}