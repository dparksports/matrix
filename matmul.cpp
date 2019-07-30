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
//typedef vector<int> ArrayInt;
//typedef vector<ArrayInt> MatrixInt;
//typedef vector<MatrixInt> ImageInt;


// a = m x k   (row x col)
// b = k x n
//
// a:
//
// 1 2 3
// 4 5 6
// 7 8 9
//
// b:
//
// 2 4 6
// 2 4 6
// 2 4 6

vector<vector<int>> multiply(const vector<vector<int>> &a, const vector<vector<int>> &b) {
    int m = a.size();
    int n = b[0].size();
    vector<vector<int>> result(m, vector<int>(n, 0));

    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b[0].size(); j++) {
            for (int k = 0; k < b.size(); k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}

void printMatrix(const vector<vector<int>> &matrix) {
    long m = matrix.size();
    long n = matrix[0].size();

    for (int row = 0; row < m; row++) {
        for (int col = 0; col < n; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void initMatrix(vector<vector<int>> &matrix) {
    long m = matrix.size();

    int count = 1;
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < m; col++) {
            matrix[row][col] = count;
            count++;
        }
    }
}

void multiplyMatrix() {
//    vector<vector<int>> a = {{1,2,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{2,4,6}, {2,4,6}, {2,4,6}};

//    vector<vector<int>> a = {{12,7,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{5,8,1,2}, {6,7,3,0}, {4,5,9,1}};

    vector<vector<int>> a = {{1, 2, 3},
                             {2, 3, 4},
                             {1, 1, 1}};
    vector<vector<int>> b = {{4, 5, 6},
                             {7, 8, 9},
                             {4, 5, 7}};

    vector<vector<int>> result = multiply(a, b);
    printMatrix(result);

    cout << endl;
}

int main(int argc, const char *argv[]) {
    multiplyMatrix();
    return 0;
}
