#include <iostream>
#include<vector>
using namespace std;

class Stack {
    int* stackArr;
    int capacity;
    int topIdx;

public:
    Stack(int size = 100) {
        capacity = size;
        stackArr = new int[capacity];
        topIdx = -1;
    }

    ~Stack() {
        delete[] stackArr;
    }

    void push(int x) {
        if(topIdx >= capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }

        stackArr[++topIdx] = x;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return stackArr[topIdx--];
    }   

    int top() {
        if(isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return stackArr[topIdx];
    }

    bool isEmpty() {
        return topIdx == -1;
    }
};

int main() {
    Stack s;
    vector<string> commands = {"ArrayStack", "push", "push", "top", "pop", "isEmpty"};
    vector<vector<int>> inputs = {{}, {5}, {10}, {}, {}, {}};

    for (size_t i = 0; i < commands.size(); ++i) {
        if (commands[i] == "push") {
            s.push(inputs[i][0]);
            cout << "null ";
        } else if (commands[i] == "pop") {
            cout << s.pop() << " ";
        } else if (commands[i] == "top") {
            cout << s.top() << " ";
        } else if (commands[i] == "isEmpty") {
            cout << (s.isEmpty() ? "true" : "false") << " ";
        } else if (commands[i] == "ArrayStack") {
            cout << "null ";
        }
    }

    return 0;
} 