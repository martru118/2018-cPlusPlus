//real    0m0.667s
//user    0m0.656s
//sys     0m0.016s


#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void randSort(int sortInt[]);  //declare randSort() function
void randSwap(int& a, int& b);  //declare randSwap() function

int randSize;

int main() {
    //generate random number when time changes
    srand(time(NULL));
    
    randSize = 1000;    //set size of array
    int randArray1[randSize] = {}; //create first array
    for(int i = 0; i < randSize; i++) {
        int randint1 = rand();  //random number changes every time it is looped
        randArray1[i] = randint1;   //add random numbers into array
    }
    randSort(randArray1);   //sort first array

    randSize = 10000;   //set size of array
    int randArray2[randSize] = {}; //create secind array
    for(int i = 0; i < randSize; i++) {
        int randint2 = rand();
        randArray2[i] = randint2;
    }
    randSort(randArray2);   //sort second array
}

//sort arrays seperately
void randSort(int sortInt[]) { //pass the list from main() as a parameter
    for (int i = 0; i < randSize; i ++) {    //scan the array
        for (int j = i + 1; j < randSize; j++) { //sort the array
            randSwap(sortInt[i], sortInt[j]);
        }
    }
}

//swap arrays seperately
void randSwap(int& a, int& b) {
    int ab;

    //swap the values of a and b
    if (a > b) {
        ab = a;
        a = b;
        b = ab;
    }
}
