#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int mode() {
    int input;
    int n;
    int sum = 0;

    cin >> n;
    vector<int> numbers(n);

    for (int i = 0; i < n; ++i) {
        cin >> input;
        numbers[i] = input;
        sum += input;
    }

    sort(numbers.begin(),numbers.end());


    float mean = sum / (n * 1.0);
    printf("%4.1f", mean);
    cout << endl;

    float median = 0;
    if (numbers.size() % 2 == 0 ) {
        int index = numbers.size() / 2;
        int prev = numbers[index - 1];
        int next = numbers[index];
        median = (prev + next) / 2.0;
    } else {
        int index = numbers.size() / 2 + 1;
        median = numbers[index];
    }
    printf("%4.1f", median);
    cout << endl;


    int value = 0;
    map<int, int> map;
    int maxCount = 0;
    int maxNumber = 0;

    for (int j = 0; j < numbers.size(); ++j) {
        map[numbers[j]] += 1;

        if (map[numbers[j]] > maxCount) {
            maxCount = map[numbers[j]];
            maxNumber = numbers[j];
        };
    }

    printf("%d", maxNumber);
//    cout <<  endl;
}

int main(int argc, const char *argv[]) {
    mode();

    return 0;
}
