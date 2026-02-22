#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> slidingWindowMax(vector<int> arr, int k) {
    vector<int> ans;
    // max heap: {value, index}
    priority_queue<pair<int, int>> pq;

    // Build first window
    for(int i=0; i<k; i++) {
        pq.push(make_pair(arr[i], i));
    }

    ans.push_back(pq.top().first);

    // for remaining windows check if top is not part of window then pop it
    for(int i=k; i<arr.size(); i++) {
        pq.push(make_pair(arr[i], i));

        while(!pq.empty() && pq.top().second <= (i-k)) {
            pq.pop();
        }
        
        ans.push_back(pq.top().first);
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;


    return 0;
}