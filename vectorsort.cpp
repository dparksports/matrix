#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int sortvector() {
    vector<int> v;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        v.push_back(value);
    }

    sort(v.begin(), v.end());
    for (int i = 0; i < n; ++i) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int eraseVector() {
    vector<int> v;
    int n, value;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> value;
        v.push_back(value);
    }

    int index;
    cin >> index;
    index--;
    v.erase(v.begin()+index);

    int a,b;
    cin >> a >> b;
    a--;
    b--;
    v.erase(v.begin()+a, v.begin()+b);

    cout << v.size() << endl;

    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main(int argc, const char *argv[]) {
//    sortvector();
    eraseVector();

    return 0;
}
