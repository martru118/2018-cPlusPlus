#include <iostream>
#include <new>

using namespace std;

int main() {
    const int size = 3;

    //create the dynamic array
    char** xGrid = new char*[size];
    for (int i = 0; i < size; i++) {
        xGrid[i] = new char[size];
    }

    //insert character X into array
    for (int x = 0; x < 3; x++) {
        for (int y = 0; y < 3; y++) {
            xGrid[x][y] = 'X';
        }
    }

    //output the array as a grid
    for (int j = 0; j < size; j++) {
        for (int k = 0; k < size; k++) {
            cout << xGrid[j][k];
        }

        cout << endl;
    }

    //delete the array from memory
    for (int d = 0; d < 3; d++) {
        delete[] xGrid[d];
    }
    delete[] xGrid;

}
