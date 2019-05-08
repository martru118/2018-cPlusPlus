//Lecture 17: Dynamic Arrays
#include <iostream>
#include <cstdlib>

using namespace std;

typedef int* IntPtr;

int main() {
    int arrSIZE = 5;
    const int INCREMENT = 10;
    int enterInt;
    int index = 0;
    int *numbers = new int[arrSIZE];

    cout << "Enter a number of positive integers: (-1 when done)" << endl;
    cin >> enterInt;
    while(enterInt > -1) {
        numbers[index] = enterInt;
        index++;
        if(index == arrSIZE) {
            //create a larger array
            IntPtr temp = new int[arrSIZE+INCREMENT];
            for(int i = 0; i < arrSIZE; i++) {
                temp[i] = numbers[i];
            }
            delete[] numbers;
            numbers = temp;
            arrSIZE += INCREMENT;
        }

        //read the next value
        cin >> enterInt;
    }

    cout << endl;

    for (int j = 0; j < index; j++) {
        cout << numbers[j] << " ";
    }

    cout << endl;

    delete[] numbers;

    
    return 0;
}
