//Lecture 10
#include <iostream>

using namespace std;

int main()
{
    srand(5);
    int count = 1;
    cout << "How many numbers do you need? ";
    cin >> count;
    for (int i=0; i < count; i++) {
    cout << "rand() = " << rand()%100 << endl;
    }

    return 0;
}
