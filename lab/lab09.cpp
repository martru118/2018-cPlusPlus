//TIC-TAC-TOE AGAIN [game]

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <new>

using namespace std;

const int SIZE = 3;

void displayBoard(string **b);
bool userFirst();
bool currentPlayerWon(string **b, string symbol);
bool generateComputerMove(string **b, int& r, int& c);

int main() {
    //construct board
    string **board = new string*[SIZE];
    for (int b = 0; b < SIZE; b++) {
        board[b] = new string[SIZE];
    }

    int position_id = 1;
    for (int i=0; i< SIZE; i++) {
        for (int j=0; j < SIZE; j++) {
            board[i][j] = to_string(position_id);
            position_id++;
        }
    }

    //Initial game output
    cout << "Welcome to Tic-Tac-Toe" << endl;

    bool userTurn = userFirst();
    if (userTurn == true) {
        cout << "Player goes first!" << endl;
    } else {
        cout << "Computer goes first!" << endl;
    }

    int positionsRemaining = SIZE * SIZE;
    bool userWon = false;
    bool computerWon = false;

    //Loop for turn taking in game
    while ((positionsRemaining > 0) && (!userWon) && (!computerWon)) {
        displayBoard(board);
        bool validMove = false;

        //User's turn
        if (userTurn) {
            while (!validMove) {
                int position_id;
                cout << "Enter a position: ";
                cin >> position_id;

                if ((position_id <= (SIZE*SIZE)) && (position_id > 0)) {
                    int row = (position_id-1)/SIZE;
                    int col = (position_id-1)%SIZE;

                    if ((board[row][col] != "X") && (board[row][col] != "O")) {
                        board[row][col] = "X";
                        validMove = true;
                    } else {
                        cout << "Position already used. Try again." << endl;
                    }

                } else {
                    cout << "Position invalid. Try again." << endl;
                }
            }
            positionsRemaining--;
            userWon = currentPlayerWon(board, "X");
            userTurn = false;
        
        //Computer's turn
        } else {
            srand(time(NULL));
			int row = 0; 
			int col = (position_id-1)%SIZE;
			bool move_made = generateComputerMove(board, row, col);

            if (positionsRemaining >= 8) {
                //first move is always center
                while(!validMove) {
                    if (board[1][1] == "5") {
                        board[1][1] = "O";
                        validMove = true;
                    } else {
                        //center is taken
                        row = rand()%SIZE;
                        col = rand()%SIZE;

                        //prevent overriding characters
                        if (board[row][col] != "X" && board[row][col] != "O") {
                            board[row][col] = "O";
                            validMove = true;
                        }
                    }
                }
            } else {
                while(!validMove) {
                    //when a pattern is found
                    if(move_made == true) {
                        if (board[row][col] != "X" && board[row][col] != "O") {
                            board[row][col] = "O";
                            validMove = true;
                        }

                    } else {
                        //play random position when there is no pattern found
                        while(!validMove) {
                            row = rand()%SIZE;
                            col = rand()%SIZE;

                            if (board[row][col] != "X" && board[row][col] != "O") {
                                board[row][col] = "O";
                                validMove = true;
                            }
                        }
                    }
                }
            }

            positionsRemaining--;
            computerWon = currentPlayerWon(board, "O");
            userTurn = true;
        }
    }

    //Display game result
    displayBoard(board);
    if (userWon) {
        cout << "Congratulations! You have won!" << endl;
    } else if (computerWon) {
        cout << "The computer has won. Try again." << endl;
    } else {
        cout << "Out of moves. Try again." << endl;
    }

    //delete dynamic board
    for(int del = 0; del < SIZE; del++) {
        delete[] board[del];
    }
    delete[] board;


    return 0;
}

void displayBoard(string **b) {
    cout << "Tic-tac-toe board:" << endl << endl;
    for (int i=0; i< SIZE; i++) {
        for (int j=0; j < SIZE; j++) {
            cout << b[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

bool userFirst() {
    //set seed for random number generation
    srand(time(NULL));

    //generate a random number: 0 for computer, 1 for user
    int num = rand()%2;
    if (num == 0) {
        return false;
    }
    return true;
}

//Return true if player/computer with symbol (X or O) has won
bool currentPlayerWon(string **b, string symbol) {
    //Horizontal case: Loop through each row
    for (int i=0; i < SIZE; i++) {
        bool rowWinDetected = true;
        //Check all positions in row and see if they are the same symbol
        for (int j = 0; j < SIZE; j++) {
            if (b[i][j] != symbol) {
                rowWinDetected = false;
            }
        }
        if (rowWinDetected) {
            return true;
        }
    }

    //Vertical case: Loop through each column
    for (int i=0; i < SIZE; i++) {
        bool colWinDetected = true;

        //Check all positions in column and see if they are the same symbol
        for (int j = 0; j < SIZE; j++) {
            if (b[j][i] != symbol) {
                colWinDetected = false;
            }
        }

        if (colWinDetected) {
            return true;
        }
    }

    //Diagonal case #1
    bool diagonal1WinDetected = true;
    for (int i=0; i < SIZE; i++) {
        if (b[i][i] != symbol) {
            diagonal1WinDetected = false;
        }
    }

    if (diagonal1WinDetected) {
        return true;
    }

    //Diagonal case #2
    bool diagonal2WinDetected = true;
    for (int i=0; i < SIZE; i++) {
        if (b[(SIZE-1)-i][i] != symbol) {
            diagonal2WinDetected = false;
        }
    }
    if (diagonal2WinDetected) {
        return true;
    }

    //otherwise win not diagonal2WinDetected
    return false;
}

//RULE: Find a pair of "O"s and/or "X"s
bool generateComputerMove(string **b, int& r, int& c) {
	string xo;

	//check for two letters
	for(int letter = 0; letter < 2; letter ++) {
		if(letter == 0) {
			xo = "O";	//first check "O"
		} else {
			xo = "X";	//then check "X"
		}

        //check each diagonal
		if(b[1][1] == xo && b[2][2] == xo) {
            if (b[0][0] == "1") {
                r = 0;
                c = 0;
                return true;
            }
		} else if(b[0][0] == xo && b[2][2] == xo) {
            if (b[1][1] == "5") {
                r = 1;
                c = 1;
                return true;
            }
		} else if(b[0][2] == xo && b[2][0] == xo){
            if (b[1][1] == "5") {
                r = 1;
                c = 1;
                return true;
            }
		} else if(b[0][0] == xo && b[1][1] == xo) {
            if(b[2][2] == "9") {
                r = 2;
                c = 2;
                return true;
            }
		} else if(b[1][1] == xo && b[2][0] == xo) {
            if (b[0][2] == "3") {
                r = 0;
                c = 2;
                return true;
            }
		} else if(b[0][2] == xo && b[1][1] == xo) {
            if (b[2][0] == "7") {
                r = 2;
                c = 0;
                return true;
            }
		}
        
        //check each row
		for(int i = 0; i < SIZE; i++) {
			if(b[i][0] == xo && b[i][1] == xo) {
                if (b[i][2] == "3" || b[i][2] == "6" || b[i][2] == "9") {
                    r = i;
                    c = 2;
                    return true;
                }
			} else if(b[i][1] == xo && b[i][2] == xo) {
                if (b[i][0] == "1" || b[i][0] == "4" || b[i][0] == "7") {
                    r = i;
                    c = 0;
                    return true;
                }
			} else if(b[i][0] == xo && b[i][2] == xo) {
                if (b[i][1] == "2" || b[i][1] == "5" || b[i][1] == "8") {
                    r = i;
                    c = 1;
                    return true;
                }
			}
		}

		//check each column
		for(int j = 0; j < SIZE; j++) {
			if(b[0][j] == xo && b[1][j] == xo) {
                if (b[2][j] == "7" || b[2][j] == "8" || b[2][j] == "9") {
                    r = 2;
                    c = j;
                    return true;
                }
			} else if(b[1][j] == xo && b[2][j] == xo) {
                if (b[0][j] == "1" || b[0][j] == "2" || b[0][j] == "3") {
                    r = 0;
                    c = j;
                    return true;
                }
			} else if(b[0][j] == xo && b[2][j] == xo) {
                if (b[1][j] == "4" || b[1][j] == "5" || b[1][j] == "6") {
                    r = 1;
                    c = j;
                    return true;
                }
			}
		}
	}

    //when there are no matches
	return false;
}
