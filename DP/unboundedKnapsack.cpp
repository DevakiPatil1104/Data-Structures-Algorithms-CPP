#include <iostream>
#include <vector>
using namespace std;

// Unbounded Knapsack (tabulation) => O(n*W)
int knapsackTab(vector<int> val, vector<int> wt, int W, int n) {
    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<W+1; j++) {
            int itemWt = wt[i-1];
            int itemVal = val[i-1];

            if(itemWt <= j) { //valid item
                /*even after including one item we can take it multiple times so 
                remaining items will not become i-1..they will remain i*/
                dp[i][j] = max(itemVal+dp[i][j-itemWt], dp[i-1][j]); 

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

    cout << "maxProfit = " << knapsackTab(val, wt, W, n) << endl;

    return 0;
}