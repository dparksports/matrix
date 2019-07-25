#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int doset() {
    int n;
    cin >> n;

    vector<bool> exists;
    set<int> s;
    int op, value;
    for (int i = 0; i < n; ++i) {
        cin >> op >> value;
        if (op == 1) {
            s.insert(value);
        }
        if (op == 2) {
            s.erase(value);
        }
        if (op == 3) {
            set<int>::iterator iterator = s.find(value);
            exists.push_back(iterator != s.end());
        }
    }

    for (int j = 0; j < exists.size(); ++j) {
        if (exists[j])
            cout << "Yes" << endl;
        else
            cout << "No" << endl;

    }
    cout << endl;
}

int main(int argc, const char *argv[]) {
    doset();

    return 0;
}
