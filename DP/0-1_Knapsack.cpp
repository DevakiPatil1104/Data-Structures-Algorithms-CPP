#include <iostream>
#include <vector>
using namespace std;

// normal recursion => O(2^n)
int knapsackRec(vector<int> val, vector<int> wt, int W, int n) {
    if(n == 0 || W == 0) { //base case
        return 0;
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) { //valid wt
        // include item
        int ans1 = knapsackRec(val, wt, W-itemWt, n-1) +itemVal;

        // exclude item
        int ans2 = knapsackRec(val, wt, W, n-1); //no change W and profit

        return max(ans1, ans2);

    } else { //invalid wt
        // exclude item
        return knapsackRec(val, wt, W, n-1);
    }
}


// DP approach (memoization) => O(n*W)
int knapsackMemo(vector<int> val, vector<int> wt, int W, int n, vector<vector<int>>& dp) {
    if(n == 0 || W == 0) { //base case
        return 0;
    }

    if(dp[n][W] != -1) { //val already calculated previously
        return dp[n][W];
    }

    int itemWt = wt[n-1];
    int itemVal = val[n-1];

    if(itemWt <= W) { //valid wt
        // include item
        int ans1 = knapsackMemo(val, wt, W-itemWt, n-1, dp) +itemVal;

        // exclude item
        int ans2 = knapsackMemo(val, wt, W, n-1, dp); //no change W and profit

        dp[n][W] = max(ans1, ans2);

    } else { //invalid wt
        // exclude item
        dp[n][W] = knapsackMemo(val, wt, W, n-1, dp);
    }

    return dp[n][W]; //final ans
}


// DP approach (tabulation) => O(n*W)
int knapsackTab(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) { //valid item
                dp[i][j] = max(itemVal+dp[i-1][j-itemWt], dp[i-1][j]);

            } else { //invalid item
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << "tabulation table" << endl;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][W];
}


int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1)); // rows=items and cols=W

    cout << knapsackRec(val, wt, W, n) << endl;

    cout << endl;

    cout << knapsackMemo(val, wt, W, n, dp) << endl;
    cout << "memoization matrix" << endl;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<W+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    cout << knapsackTab(val, wt, W, n) << endl;

    return 0;
}