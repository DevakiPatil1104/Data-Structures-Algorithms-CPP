#include <iostream>
#include <vector>
using namespace std;

int fibRec(int n) {  // O(2^n)
    if(n == 0 || n == 1) {
        return n;
    }

    return (fibRec(n-1) + fibRec(n-2));
}

int fibDP(int n, vector<int>& f) { // O(n)
    if(n == 0 || n == 1) {
        return n;
    }

    if(f[n] != -1) {
        return f[n];
    }

    f[n] = fibDP(n-1, f) + fibDP(n-2, f);
    return f[n];
}

int main() {
    int n = 6;
    vector<int> f(n+1, -1);

    cout << "fibonacci of 6 by rec = " << fibRec(n) << endl;
    cout << "fibonacci of 6 by DP rec = " << fibDP(n, f) << endl;
    
    return 0;
}