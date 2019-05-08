//Lecture 9
#include <iostream>
#include <string>

//using namespace std;
//cout and endl will accessible to all namespaces
//in this file because we used the "using" directive
//outside of a code block (i.e. globally)
using std::cout;    //accessible to all files
using std::endl;    //accessible to all files

namespace second_row {
  void jon();
}

namespace first_row {
  void jon();
}

namespace {
  void jon();
}

//all of the code in this file (unless otherwise noted)
//is part of the global namespace
int main() {
  int temp = 5;
  //cout and endl are both from the std namespace
  cout << "temp is " << temp << endl;
  cout << "This is a test." << endl;

  first_row::jon();
  {
    using namespace first_row;
    ::jon();
  }
  second_row::jon();
  return 0;
}

namespace second_row {
  void jon() {
    cout << "Hi! I'm Jon from row 2. I prefer Jonathan."
         << endl;
  }
}

namespace first_row {
  void jon() {
    cout << "Hi! I'm Jo(h)n from the front row."
         << " Please spell my name correctly."
         << endl;
  }
}

namespace {
  void jon() {
    cout << "Hi! I'm Jon Z. from the back of class."
         << " I'm currently in the unnamed namespace."
         << endl;
  }
}
