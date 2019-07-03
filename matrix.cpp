/*
Let's start by writing our own Matrix class!

It should:
* Work for any size 2D matrix of type double
* Access and set any particular element, safely
* print in a human-readable way
* Support multiplication with a scalar
* Support multiplication with another Matrix
* Make sure to test it!
* NxN 

m1:
7 4 7
6 2 3
1 2 2

m2:
5 4 7
2 1 8
5 4 8

m1 * m2:
78 60 137
49 38 82
19 14 39

m3:
7 4 7 9
6 2 3 6
1 1 1 1
4 3 5 8
*/

#include <iostream>
using namespace std;

class Matrix {
  private vector<vector<double>> matrix;
  private mutex mutex;
  
  Matrix() { }
  // implement me!
  
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
  
};

void main() {
 
 

}
