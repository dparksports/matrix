#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


void lower_bound() {
    int n;
    cin >> n;

    int value;
    vector<int> numbers(n,0);
    for (int i = 0; i < n; ++i) {
        cin >> value;
        numbers[i] = value;
    }

    int query;
    int nQueries;
    vector<int>::iterator low_bound;
    cin >> nQueries;

    for (int j = 0; j < nQueries; ++j) {
        cin >> query;
        low_bound = lower_bound(numbers.begin(), numbers.end(), query);
        int index = (low_bound - numbers.begin());

        if (low_bound == numbers.end()) {
            cout << "No " << index;
        } else {
            if (numbers[index] == query) {
                cout << "Yes " << index + 1;
            } else {
                cout << "No " << index + 1;
            }
        }
        cout << endl;
    }

}

int main(int argc, const char *argv[]) {
    lower_bound();

    return 0;
}
