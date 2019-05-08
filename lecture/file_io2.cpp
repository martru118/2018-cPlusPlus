//Lecture 8
//appending to a file
#include <iostream> //library for terminal input/output
#include <string> //library for strings
#include <fstream> //library for file input/output

using namespace std;

int main() {
  string filename;
  const int SIZE = 5; //size of data array
  string data[SIZE];

  //FILE OUTPUT
  cout << "Enter output filename: ";
  cin >> filename;
  //ofstream myOutput;
  //myOutput.open(filename);
  //the above two lines are the same as...
  ofstream myOutput(filename, ios::app);

  cout << "Enter " << SIZE
        << " words to store in a file in reverse order: ";
  for (int i=0; i < SIZE; i++) {
    cin >> data[i];
  }

  //write to file
  for (int i = SIZE-1; i >= 0; i--) {
    myOutput << data[i] << endl;
  }

  //Always close the file when finished
  myOutput.close();

  //FILE INPUT
  cout << "Reading in " << filename << "..." << endl;
  ifstream myInput(filename);

  //Read from the filename
  while(!myInput.eof()) {
    string line;
    myInput >> line;
    cout << line << endl;
  }


  //Close the file
  myInput.close();

  return 0;
}
