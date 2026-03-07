#include <iostream>
#include <vector>
using namespace std;

// Unbounded Knapsack variation (tabulation) => O(n*rodLen)
int rodCutting(vector<int>& price, vector<int>& length, int rodLen) {
    int n = length.size(); //no. of piece len possible
    vector<vector<int>> dp(n+1, vector<int>(rodLen+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<rodLen+1; j++) {
            int pieceLen = length[i-1];
            int pieceVal = price[i-1];

            if(pieceLen <= j) { //valid piece
                dp[i][j] = max(pieceVal + dp[i][j-pieceLen], dp[i-1][j]); 

            } else { //invalid piece
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    
    cout << "tabulation table" << endl;
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<rodLen+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return dp[n][rodLen];
}


int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> length = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLen = 8;

    cout << "maxProfit = " << rodCutting(price, length, rodLen) << endl;

    return 0;
}