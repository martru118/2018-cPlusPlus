//Lecture 16: Dynamic Variables
#include <iostream>
#include <string>

using namespace std;

typedef int* IntPtr;

int main() {
     const int rows = 5;
     const int cols = 6;
     IntPtr *p1 = new IntPtr[cols];    //same as int **p1(pointing at a pointer)

     //for each IntPtr create a dynamic array of ints
     for(int i = 0; i < cols; i++) {
          p1[i] = new int[rows];
     }

     for(int c = 0; c < cols; c++) {
          for(int r = 0; r < rows; r++) {
               p1[c][r] = c*r;
          }

          cout << p1[c] << endl;
     }

     //deleting a dynamic two dimensional array
     for(int i = 0; i < cols; i++) {
          // delete the arrays of ints first
          delete[] p1[i];
     }

     //then delete the array of IntPtrs
     delete[] p1;

     return 0;
}