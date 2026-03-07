#include <iostream>
#include <vector>
#include <string>
using namespace std;

// normal recursion => O(2^n+m)
int lcsRec(string str1, string str2) {
    if(str1.size() == 0 || str2.size() == 0) return 0; //base case
    
    int n = str1.size();
    int m = str2.size();
    
    if(str1[n-1] == str2[m-1]) { //cmp last char of both str
        return 1 + lcsRec(str1.substr(0, n-1), str2.substr(0, m-1));  //if same then remove that and check for rest
    } else { // not same then either remove from 1st or 2nd str
        int ans1 = lcsRec(str1.substr(0, n-1), str2); 
        int ans2 = lcsRec(str1, str2.substr(0, m-1)); 
        return max(ans1, ans2);
    }
}


// DP approach (memoization) => O(n*W)
int lcsMemo(string str1, string str2, vector<vector<int>>& dp) {
    if(str1.size() == 0 || str2.size() == 0) return 0; //base case
    
    int n = str1.size();
    int m = str2.size();

    if(dp[n][m] != -1) {
        return dp[n][m];
    } else {
        if(str1[n-1] == str2[m-1]) { //cmp last char of both str
            dp[n][m] = 1 + lcsMemo(str1.substr(0, n-1), str2.substr(0, m-1), dp);  //if same then remove that and check for rest
        } else { // not same then either remove from 1st or 2nd str
            int ans1 = lcsMemo(str1.substr(0, n-1), str2, dp); 
            int ans2 = lcsMemo(str1, str2.substr(0, m-1), dp); 
            dp[n][m] = max(ans1, ans2);
        }
    }
    return dp[n][m];
}


// DP approach (tabulation) => O(n*W)
int lcsTab(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=1; i<n+1; i++) {
        for(int j=1; j<m+1; j++) {
            if(str1[i-1] == str2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}
   

int main() {
    string str1 = "abcd";
    string str2 = "aceb";

    cout << "LCS length = " << lcsRec(str1, str2) << endl;

    vector<vector<int>> dp(str1.size()+1, vector<int>(str2.size()+1, -1));
    cout << "LCS length = " << lcsMemo(str1, str2, dp) << endl;
    cout << "memoization matrix" << endl;
    for(int i=0; i<str1.size()+1; i++) {
        for(int j=0; j<str2.size()+1; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    cout << "LCS length = " << lcsTab(str1, str2) << endl;

    return 0;
}