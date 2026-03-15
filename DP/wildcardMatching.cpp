#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isMatch(string t, string p) {
    int n = t.size();
    int m = p.size();

    // dp[i][j] = true if first i chars of text match first j chars of pattern
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    
    // empty pattern matches empty text
    dp[0][0] = true;
    
    // handle patterns like *, **, *** that can match empty string
    for(int j = 1; j <= m; j++) {
        if(p[j-1] == '*') {
            dp[0][j] = dp[0][j-1];  // '*' can represent empty sequence
        } else {
            dp[0][j] = false;       // other chars can't match empty text
        }
    }

    // fill the DP table
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {

            // '?' matches any single char OR exact character match
            if(p[j-1] == '?' || p[j-1] == t[i-1]) {
                dp[i][j] = dp[i-1][j-1];
            }

            // '*' can match:
            // 1) multiple chars -> dp[i-1][j]
            // 2) empty sequence -> dp[i][j-1]
            else if(p[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }
    
    // final result: full text vs full pattern
    return dp[n][m];
}

int main() {
    string text = "baaabab", pattern = "**ba****ab*";
    cout << isMatch(text, pattern) << endl;
    
    return 0;
}