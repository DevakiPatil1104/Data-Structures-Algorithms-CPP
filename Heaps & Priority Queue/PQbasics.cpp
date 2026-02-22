#include<iostream>
#include<queue>
using namespace std;

int main() {
    // priority_queue<int> pq; //max heap
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(5);
    pq.push(10);
    pq.push(3);
    pq.push(6);
    pq.push(9);

    cout << "top: " << pq.top() << endl;
    while(!pq.empty()) {
        cout << pq.top() << endl;
        pq.pop();
    }

    priority_queue<string> pq2;

    pq2.push("helloworld");
    pq2.push("apnacollege");
    pq2.push("c++");
    pq2.push("rainbow");
    pq2.push("devaki");

    cout << "top: " << pq2.top() << endl;
    while(!pq2.empty()) {
        cout << pq2.top() << endl;
        pq2.pop();
    }
    
    return 0;
}