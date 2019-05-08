#include <iostream>

using namespace std;

void sorter(int sortInt[]);    //declare sorter() function
void swapper(int& a, int& b);   //declare swapper() function

const int numSize = 5;  //set size of array

int main() {
    int numArray[numSize] = {}; //create array

    //prompt user for 5 integers
    cout << "Enter 5 integers:" << endl;
    //Enter integers using the loop
    for(int i=0; i < numSize; i++) {
        cin >> numArray[i]; //insert user inputs into array
    }

    //sort numArray[]
    sorter(numArray);

    //leave sorter, then output list
    cout << "\nThe array of integers sorted in ascending order is:" << endl;
    cout << numArray[0] << " " << numArray[1] << " " <<  numArray[2] << " " << numArray[3] << " " << numArray[4] << endl;
}

//sort numbers here
void sorter(int sortInt[]) { //pass the list from num as a parameter
    for (int i = 0; i < numSize; i ++) {    //scan the array
        for (int j = i + 1; j < numSize; j++) { //sort the array
            swapper(sortInt[i], sortInt[j]);    //swap the elements in the sortInt array
        }
    }
}

//swap numbers here
void swapper(int& a, int& b) { //pass the list from main() as a parameter
    int ab;

    //swap the values of a and b
    if (a > b) {
        ab = a;
        a = b;
        b = ab;
    }
}
