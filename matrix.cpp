#include <iostream>
#include <vector>

using namespace std;

class Matrix {
  private vector<vector<double>> matrix;
  private mutex mutex;
  
  Matrix() { }
  
  void init(const int &m, const int &n, const int &intValue) {
   vector<vector<double>> matrixA(m, vector<double>(n, initValue));
  }
  
  void set(int column, int row, double value) throw RangeException {
    // making sure the column and row indice are within the matrix size.
    if (matrix.size() < column) && (matirx[column].size < row) {
     assert()
    } 

    mutex.lock();
    matrix[column][row] = value;
    mutex.unlock();
  }
  
  double get(int column, int row) {
    if (matrix.size() < column) && (matirx[column].size < row) {
     assert()
    } 

    return matrix[column][row];
  }
  
  
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

};

void main() {
//    MatrixInt a = {{1,2,3}, {4,5,6}, {7,8,9}};
//    MatrixInt b = {{2,4,6}, {2,4,6}, {2,4,6}};

//    vector<vector<int>> a = {{12,7,3}, {4,5,6}, {7,8,9}};
//    vector<vector<int>> b = {{5,8,1,2}, {6,7,3,0}, {4,5,9,1}};

    vector<vector<int>> a = {{7,4,7}, {6,2,3}, {1,2,2}};
    vector<vector<int>> b = {{5,4,7}, {2,1,8}, {5,4,8}};

    vector<vector<int>> result = multiply(a, b);
    printMatrix(result);

    cout << endl;
    return 0;
}
