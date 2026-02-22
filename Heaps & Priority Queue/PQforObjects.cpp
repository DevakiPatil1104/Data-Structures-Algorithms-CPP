#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Student {
public:
    string name;
    int marks;

    Student(string name, int marks) {
        this->name = name;
        this->marks = marks;
    }

    bool operator < (const Student &obj) const {
        return this->marks < obj.marks;
    }
};

int main() {
    priority_queue<Student> pq;
    
    pq.push(Student("Devaki", 97));
    pq.push(Student("Aditi", 65));
    pq.push(Student("Raj", 85));

    while(!pq.empty()) {
        cout << "top = " << pq.top().name << ", " << pq.top().marks << endl;
        pq.pop();
    }

    return 0;
}