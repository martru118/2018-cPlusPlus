#include <iostream>
#include <new>

using namespace std;

int main() {
    int position;
    const int size = 4;

    //create dynamic two-dimensional array
    char** xo = new char*[size];
    for (int i = 0; i < size; i++) {
        xo[i] = new char[size];
    }

    //fill the array with x's and o's
    for (int x = 0; x < size; x++) {
        //place x's and o's at random spots
        srand(time(NULL));
        position = random() % size;

        for (int o = 0; o < size; o++) {
            xo[x][position] = 'X';
            xo[position][o] = 'O';

            cout << xo[position][position];
        }
        cout << endl;
    }

    //delete the array
    for (int d = 0; d < size; d++) {
        delete[] xo[d];
    }
    delete[] xo;


    return 0;
}
