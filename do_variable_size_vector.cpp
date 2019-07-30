//
//  main.cpp
//  transpose
//
//  Created by Dan Park on 6/19/19.
//  Copyright © 2019 Dan Park. All rights reserved.
//

#include <vector>
#include <string>
#include <sstream>
#include <iostream>

#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cassert>

#include <exception>

#include <algorithm>

using namespace std;


void printNUmber(int n) {
    if (n == 1) {
        cout << "one";
    }
    if (n == 2) {
        cout << "two";
    }
    if (n == 3) {
        cout << "three";
    }
    if (n == 4) {
        cout << "four";
    }
    if (n == 5) {
        cout << "five";
    }
    if (n == 6) {
        cout << "six";
    }
    if (n == 7) {
        cout << "seven";
    }
    if (n == 8) {
        cout << "eight";
    }
    if (n == 9) {
        cout << "nine";
    }
}

int max_of_four(int a, int b, int c, int d) {
    int max = std::max(std::max(a, b), std::max(c, d));
    return max;
}

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

void doVariableSizedArrays() {
    int n, q;
    scanf("%d %d", &n, &q);

    vector<vector<int>> arrays(n, vector<int>(0, 0));

    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d", &k);

        arrays[i].resize(k);

        for (int index = 0; index < k; index++) {
            int number;
            scanf("%d", &number);

            arrays[i][index] = number;
        }
    }

    vector<vector<int>> queries(q, vector<int>(2, 0));
    for (int k = 0; k < q; k++) {
        int i = 0, j = 0;
        scanf("%d %d", &i, &j);

        queries[k][0] = i;
        queries[k][1] = j;
    }

    for (int k = 0; k < q; k++) {
        int i = queries[k][0], j = queries[k][1];
        cout << arrays[i][j] << endl;
    }
}



int main(int argc, const char *argv[]) {
    doVariableSizedArrays();



    return 0;
}
