#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


void doMap() {
    int queries;
    cin >> queries;

    int mark;
    string name;
    int op;
    map<string,int> marks;
    vector<string> printNames;

    for (int i = 0; i < queries; ++i) {
        cin >> op >> name;
        if (op == 1) {
            cin >> mark;
            marks[name] += mark;
        }

        if (op == 2) {
            marks.erase(name);
        }

        if (op == 3) {
            cout << marks[name] << endl;
//            printNames.push_back(name);
        }
    }

//    for (int j = 0; j < printNames.size(); ++j) {
//        cout << marks[printNames[j]] << endl;
//    }
    cout << endl;
}

int main(int argc, const char *argv[]) {
    doMap();

    return 0;
}
