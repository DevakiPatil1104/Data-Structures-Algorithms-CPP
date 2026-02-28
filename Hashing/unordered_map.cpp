#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<string, int> m;

    m["India"] = 150;
    m["China"] = 150;
    m["US"] = 50;
    m["Nepal"] = 10;

    for(pair<string, int> country : m) {
        cout << country.first << ", " << country.second << endl;
    }

    if(m.count("Canada")) {
        cout << "Canada exists\n";
    } else {
        cout << "Canada doesn't exist\n";
    }
    if(m.count("Nepal")) {
        cout << "Nepal exists\n";
    } else {
        cout << "Nepal doesn't exist\n";
    }

    m.erase("Nepal");
    cout << "after erase\n";
    if(m.count("Nepal")) {
        cout << "Nepal exists\n";
    } else {
        cout << "Nepal doesn't exist\n";
    }


    return 0;
}