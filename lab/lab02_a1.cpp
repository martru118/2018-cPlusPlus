#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    //generate random number whenever time changes
    srand(time(NULL));

    //start game
    cout << "----------------------------------" << endl;
    cout << "Welcome to Guess That Number!" << endl;
    cout << "----------------------------------" << endl;

    //initial variables
    int num;
    int gameRound = 0;  //initial round
    int random5 = 5;    //initial range
    int randint = rand() % random5;    //generate random number from 0 to the value of random5
    int tries = 5;  //initial number of tries
    int guess;
    bool correct = true;

    cout << "\nRound " << (gameRound += 1) << endl;    //initial round marker

    //start incrementing rounds
    while (correct) {
        guess = 0;  //initial number of guesses

        while(guess < 5) {  //five guesses per round
            cout << "Guess a number less than " << random5 << ": ";
            cin >> num;

            if (num != randint) {   //when number is incorrect
                tries -= 1; //decrease number of tries
                if (tries == 0) {   //when user runs out of tries
                    cout << "Incorrect! Out of guesses :(" << endl;
                    guess = 5;  //exit guess loop
                    correct = false;    //exit correct loop
                } else {
                    guess += 1; //increase number of guesses by 1
                    cout << "Incorrect! Try again (" << tries << " tries remaining)!" << endl;
                }
            
            //refresh variables to stay in guess loop
            } else {    //when user guesses the correct number
                guess = 0;
                tries = 5;
                cout << "Correct! The number was " << randint << endl;
                cout << "\nRound " << (gameRound += 1) << endl; //display next round
                randint = rand() % (random5 *= 2);  //double the interval each round
            }
        }
    }

    cout << "\nGame Over!" << endl;

    
    return 0;
}