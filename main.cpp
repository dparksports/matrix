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

void multiplyMatrix() {
//    vector<vector<int>> a = {{1,2,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{2,4,6}, {2,4,6}, {2,4,6}};

//    vector<vector<int>> a = {{12,7,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{5,8,1,2}, {6,7,3,0}, {4,5,9,1}};

    vector<vector<int>> a = {{7, 4, 7},
                             {6, 2, 3},
                             {1, 2, 2}};
    vector<vector<int>> b = {{5, 4, 7},
                             {2, 1, 8},
                             {5, 4, 8}};

    vector<vector<int>> result = multiply(a, b);
    printMatrix(result);

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

//void printMatrix(const vector<vector<int>> &matrix) {
//    long m = matrix.size();
//
//    for (int row = 0; row < m; row++) {
//        for (int col = 0; col < m; col++) {
//            cout << matrix[row][col] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

void transpose(vector<vector<int>> &matrix) {
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

void doTranspose() {
    int m = 6, n = 6;
    vector<vector<int>> matrix(m, vector<int>(n, 0));

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
    while (getline(ss, token, ',')) {
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
    for (int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    cout << endl;
}

class Student2 {
    const int count = 5;
    vector<int> scores;
//    vector<int> second2;
    string first;
    string last;
    int age = 0;
    int stan = 0;

public:
//    Student() {
//        vector<int> temp (count, 0);
//        second2 = temp;
//    }

    int get_age() {
        return age;
    }

    int get_standard() {
        return stan;
    }

    string get_first_name() {
        return first;
    }

    string get_last_name() {
        return last;
    }

    string to_string() {
        string value;
        value.append(std::to_string(age) + ",");
        value.append(first + ",");

        value.append(last + ",");
        value.append(std::to_string(stan));
        return value;
    }

    void set_age(int value) {
        age = value;
    }

    void set_standard(int value) {
        stan = value;
    }

    void set_first_name(string value) {
        first = value;
    }

    void set_last_name(string value) {
        last = value;
    }

    void input() {
        int score;
        for (int i=0; i < count; i++) {
            cin >> score;
            scores.push_back(score);
        }
    }

    int calculateTotalScore() {
        int sum = 0;
        for (int i=0; i < count; i++) {
            sum += scores[i];
        }
        return sum;
    }
};

//void scanName() {
//    int age, standard;
//    string first_name, last_name;
//
//    cin >> age >> first_name >> last_name >> standard;
//
//    Student st;
//    st.set_age(age);
//    st.set_standard(standard);
//    st.set_first_name(first_name);
//    st.set_last_name(last_name);
//
//    cout << st.get_age() << "\n";
//    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
//    cout << st.get_standard() << "\n";
//    cout << "\n";
//    cout << st.to_string();
//    cout << endl;
//}

//int scanStudents() {
//
//    int n; // number of students
//    cin >> n;
//    Student *s = new Student[n]; // an array of n students
//
//    for (int i = 0; i < n; i++) {
//        s[i].input();
//    }
//
//    // calculate kristen's score
//    int kristen_score = s[0].calculateTotalScore();
//
//    // determine how many students scored higher than kristen
//    int count = 0;
//    for (int i = 1; i < n; i++) {
//        int total = s[i].calculateTotalScore();
//        if (total > kristen_score) {
//            count++;
//        }
//    }
//
//    // print result
//    cout << count;
//
//}

struct Student {
    string first_name;
    string last_name;
    int age = 0;
    int standard = 0;

    Student() {
    }
};

int scanStudentStruct() {
    Student st;

    cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;
    cout << endl;
}


#include <iostream>
#include <string>
#include <sstream>
#include <exception>
using namespace std;

class BadLengthException: public exception {
private:
    int length;
    string exceptionString;

public:
    BadLengthException(int n) {
        length = n;
        exceptionString = to_string(n);
    }

    virtual const char* what() const throw()
    {
//        string temp;
//        temp.append(to_string(length));
//        exceptionString.append(temp);
        return exceptionString.c_str();
    }
};

bool checkUsername(string username) {
    bool isValid = true;
    int n = username.length();
    if(n < 5) {
        throw BadLengthException(n);
    }
    for(int i = 0; i < n-1; i++) {
        if(username[i] == 'w' && username[i+1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

int throwException() {
    int T; cin >> T;
    while(T--) {
        string username;
        cin >> username;
        try {
            bool isValid = checkUsername(username);
            if(isValid) {
                cout << "Valid" << '\n';
            } else {
                cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            cout << "Too short: " << e.what() << '\n';

            cout << endl;
        }
    }
    cout << endl;
    return 0;
}

int main(int argc, const char *argv[]) {
    throwException();
//    scanStudentStruct();
//    scanName();
//    scanStudents();

//    scanStream();
//    doTranspose();
//    scanString();


    return 0;
}
