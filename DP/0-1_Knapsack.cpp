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

// DP approach (memoization) => O(n)


// DP approach (tabulation) => O(n)



int main() {
    vector<int> val = {15, 14, 10, 45, 30};
    vector<int> wt = {2, 5, 1, 3, 4};
    int W = 7;
    int n = 5;

    cout << knapsackRec(val, wt, W, n) << endl;

    return 0;
}