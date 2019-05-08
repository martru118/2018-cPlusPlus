#include <iostream>
#include <new>

using namespace std;

void removeNumber(int **modified, int jj, int& SIZE);
void removeDuplicate(int **original, int& SIZE);

int main () {
    int arrayROWS;
    int countCOLS = 2;
    int **dynamic;
    int timeCounter = 0;

    //create a two dimensional array
    cout << "Enter the size: ";
    cin >> arrayROWS;
    dynamic = new int*[arrayROWS];
    for(int z = 0; z < arrayROWS; z++) {
        dynamic[z] = new int[countCOLS];

    }

    //prompt user for integers
    cout << "Enter the integers: " << endl;
    for(int n = 0; n < arrayROWS; n++) {
        cin >> dynamic[n][0];
    }

    cout << endl;

    //count occurances for each number
    for(int t = 0; t < arrayROWS; t++) {
        for(int u = 0; u < arrayROWS; u++) {
            if(dynamic[t][0] == dynamic[u][0]) {
                timeCounter += 1;   //increase the count by one
                dynamic[t][1] = timeCounter;    //add count to array
            }
        }
        
        timeCounter = 0;    //reset count after each number
    }

    //remove duplicate rows
    removeDuplicate(dynamic, arrayROWS);

    //display the occurances for each number
    for(int a = 0; a < arrayROWS; a++) {
        if (dynamic[a][1] == 1) {
            cout << dynamic[a][0] << " -> 1 time" << endl;
        } else {
            cout << dynamic[a][0] << " -> " << dynamic[a][1] << " times" << endl;
        }
    }

    //delete two-dimensional dynamic array
    for(int del = 0; del < arrayROWS; del++) {
        delete[] dynamic[del];
    }
    delete[] dynamic;

}

void removeNumber(int **modified, int jj, int& SIZE) {
    for(int i = jj; i < SIZE - 1; i++) {
        modified[i][0] = modified[i + 1][0];    //skip the duplicate number
        modified[i][1] = modified[i + 1][1];    //skip its count
    }

    SIZE--; //shrink the size of the array when the elements are skipped

}

void removeDuplicate(int **original, int& SIZE) {
    //find matching numbers
    for(int i = 0; i < SIZE; i++) {
        for(int j = i + 1; j < SIZE; j++) {
            if(original[i][0] == original[j][0]) {
                //skip the row of the duplicate number
                removeNumber(original, j, SIZE);

                j--;
            }
        }
    }

}
