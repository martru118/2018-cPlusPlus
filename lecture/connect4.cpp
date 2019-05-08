//Lectures 11, 12, 13: Problem Solving Strategies in C++
#include <iostream>
#include <cstdlib>

using namespace std;

//Global variables for representing game displayBoard
const int rows = 6;
const int columns = 7;
char board[columns][rows]; //2D array of 7x6
const char emp = '-';
const char p1 = 'X';
const char p2 = 'O';

//initialize Connect4 board to contain
//all empty cell
void initializeBoard();

//display contents of board
void displayBoard();

//add one piece to the board
bool addPiece(int c, bool isPlayer1);

//Check if current player has connected 4 and wins the game
bool gameWon(bool isPlayer1);

int main() {
  initializeBoard();
  displayBoard();
  
  //Create gameplay loop
  bool playerOne = true;

  //total moves made
  int totalMoves = 0;
  const int max_moves = columns*rows;

  //loop until either the game is won or the board is full
  while(totalMoves < max_moves) {
    int ycolumn;
    bool validMove = false; //explaining variable
    //Ask current player for column until valid input is entered
    while (!validMove) {
      cout << "Player";
      if (playerOne) {
        cout << "1";
      } else {
        cout << "2";
      }

      cout << " -- Select a column (0-" << columns - 1 << ") to play: ";
      cin >> ycolumn;
      validMove = addPiece(ycolumn, playerOne);
      if (!validMove) {
        cout << "Bad move! Try again." << endl;
      }
      else {
        totalMoves++;
      }
    }
    displayBoard();
    playerOne = !playerOne;
  }
  if (totalMoves == max_moves) {
    cout << "Out of moves! GAME OVER!" << endl;
  }

}

void initializeBoard() {
  for (int c = 0; c < columns; c++) {
    for (int r = 0; r < rows; r++) {
      board[c][r] = emp;
    }
  }
}

void displayBoard() {
  cout << endl << "Connect 4 Board:" << endl;
  for (int r = 0; r < rows; r++) {
    //print a single row of board
    for (int c = 0; c < columns; c++) {
      cout << board[c][r] << " ";
    }
    cout << endl; //after each row add a newline
  }

  for (int c = 0; c < columns; c++) {
    cout << c << " ";
  }
  cout << endl << endl;
}

bool addPiece(int c, bool isPlayer1) {
  //check if column is successfully
  if (board[c][0] != emp) {
    return false;
  } else {
    for (int r = rows-1; r>= 0; r--) {
      if(board[c][r] == emp) {
        if (isPlayer1) {
          board[c][r] = p1;
        } else {
          board[c][r] = p2;
        }
        break;  //break out of loop once piece is added
      } 
    }
    //return true if piece successfully added to column c
    return true;
  }

}

bool gameWon(bool isPlayer1) {
  //Check for four pieces horizontally

  //Check for 4 pieces vertically

  //Check for 4 pieces diagnolly (both directions)
}
