#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // dp initialization
        for(int i = 0; i <= n; i++)
            dp[i][0] = i;

        for(int j = 0; j <= m; j++)
            dp[0][j] = j;

        // LCS logic
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(word1[i-1] == word2[j-1]) //if last char is same then 0 opr added
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({ //if last char diff then 1 opr no. of ops on rest str lens
                        dp[i][j-1], //insert
                        dp[i-1][j], //delete
                        dp[i-1][j-1] //replace
                    });
            }
        }
        return dp[n][m];
    }


int main() {
    string str1 = "horse", str2 = "ros";

    cout << "min of operations = " << minDistance(str1, str2) << endl;

    return 0;
}