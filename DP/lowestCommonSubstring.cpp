#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lowest Common Substring problem


// DP approach (tabulation) => O(n*m)
int lcSubstr(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = 0;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans;
}
   

int main() {
    string str1 = "abcde";
    string str2 = "abgce";

    cout << "LCS length = " << lcSubstr(str1, str2) << endl; //ans = 2

    return 0;
}