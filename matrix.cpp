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

using namespace std;

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

void printMatrix(const vector<vector<int>> &matrix) {
    long m = matrix.size();
    
    for (int row = 0; row < m; row++) {
        for (int col = 0; col < m; col++) {
            cout << matrix[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void transpose(vector<vector<int>>& matrix) {
    long length = matrix.size();

    for (int row = 0; row < length; row++) {
        for (int col = 0; col < length; col++) {
            if (row == col) {
                continue;
            }

            if (row > 0) {
                int lastRow = col;
                if (row > lastRow) {
//                    cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
//                    cout << endl;
                    continue;
                }
            }
            
//            cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
            
            int temp = matrix[col][row];
            matrix[col][row] = matrix[row][col];
            matrix[row][col] = temp;
            
//            cout <<  "m[" << row << "][" << col << "] " << matrix[row][col] << " : m[" << col << "][" << row << "] " << matrix[col][row] << endl;
//            cout << endl;
        }
    }

}

void transpose() {
    int m = 6, n = 6;
    vector<vector<int>> matrix(m, vector<int>(n,0));
    
    initMatrix(matrix);
    printMatrix(matrix);
    
    transpose(matrix);
    printMatrix(matrix);
}

void scanString() {
    string s1, s2;
    cin >> s1;
    cin >> s2;
//    scanf("%s", &s1);
//    scanf("%s", &s2);

    int len1 = s1.size();
    int len2 = s2.size();

    
    cout << len1 << " " << len2 << endl;
    cout << s1 + s2 << endl;
    
    char c1 = s2[0];
    s2[0] = s1[0];
    s1[0] = c1;

    cout << s1 << " " << s2;
    cout << endl;
}

vector<int> parseInts(string str) {
    stringstream ss(str);
    string token;
    
    vector<int> ints;
    while(getline(ss, token, ',')) {
        stringstream wordstream(token);
        
        int number;
        wordstream >> number;
        ints.push_back(number);
    }
    
    return ints;
}

void scanStream() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    cout << endl;
}

int main(int argc, const char * argv[]) {
    scanStream();
//    transpose();
//    scanString();
    
    
    return 0;
}
