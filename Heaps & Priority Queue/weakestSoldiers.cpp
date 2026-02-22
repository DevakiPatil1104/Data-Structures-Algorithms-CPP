#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Row {
public:
    int count; //soldier count
    int idx; //row number

    Row(int count, int idx) {
        this->count = count;
        this->idx = idx;
    }

    bool operator < (const Row &obj) const {
        if(this->count == obj.count) { //minHeap
            return this->idx > obj.idx; //if count equal then based on min index => smaller index first
        } else {
            return this->count > obj.count; //smaller count first
        }
    }

};

vector<int> kWeakestSoldiers(vector<vector<int>> matrix, int k) {
    vector<Row> rows;
    for(int i=0; i<matrix.size(); i++) { //travel each row
        int count = 0;
        for(int j=0; j<matrix[i].size() && matrix[i][j] == 1; j++) { //travel each element in an ith row
            count++;
        }
        rows.push_back(Row(count, i));
    }

    priority_queue<Row> pq(rows.begin(), rows.end());

    vector<int> ans;

    for(int i=0; i<k; i++) {
        ans.push_back(pq.top().idx);
        pq.pop();
    }

    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 1, 1},
                                  {1, 0, 0, 0},
                                  {1, 0, 0, 0}};

    vector<int> result = kWeakestSoldiers(matrix, 2);

    for (int idx : result) {
        cout << "row" << idx << endl;
    }

    return 0;
}