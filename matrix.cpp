#include <iostream>
#include <vector>

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
        for (int j = 0; j < b[0].size(); j++ ) {
            for (int k = 0; k < b.size(); k++ ) {
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
    int max = std::max(std::max(a,b), std::max(c,d));
    return max;
}

void update(int *a,int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

void doVariableSizedArrays(){
    int n, q;
    scanf("%d %d", &n, &q);

    vector<vector<int>> arrays(n, vector<int>(0, 0));

    for (int i=0; i < n; i++) {
        int k;
        scanf("%d", &k);

        arrays[i].resize(k);

        for (int index=0; index < k; index++) {
            int number;
            scanf("%d", &number);

            arrays[i][index] = number;
        }
    }

    vector<vector<int>> queries(q, vector<int>(2, 0));
    for (int k=0; k < q; k++) {
        int i = 0, j = 0;
        scanf("%d %d", &i, &j);

        queries[k][0] = i;
        queries[k][1] = j;
    }

    for (int k=0; k < q; k++) {
        int i = queries[k][0], j = queries[k][1];
        cout << arrays[i][j] << endl;
    }
}

int main() {
     doVariableSizedArrays();


//    MatrixInt a = {{1,2,3}, {4,5,6}, {7,8,9}};
//    MatrixInt b = {{2,4,6}, {2,4,6}, {2,4,6}};

//    vector<vector<int>> a = {{12,7,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{5,8,1,2}, {6,7,3,0}, {4,5,9,1}};

//    vector<vector<int>> a = {{7,4,7}, {6,2,3}, {1,2,2}};
//    vector<vector<int>> b = {{5,4,7}, {2,1,8}, {5,4,8}};
//
//    vector<vector<int>> result = multiply(a, b);
//    printMatrix(result);
//
//    cout << endl;
//    return 0;
}

