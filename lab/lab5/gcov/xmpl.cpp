// $Id: xmpl.cpp,v 1.1 2003/09/06 21:57:18 phf Exp $

#include <string>
#include <iostream>
#include <vector>
#include <cassert>

const int MAXARGS = 16;

int main( int argc, char* argv[] ) {

  // Convert C-style arguments to C++ abstractions.
  assert( argc <= MAXARGS );
  std::vector<std::string> args( MAXARGS );
  for (int i = 0; i < argc; i++) {
    std::string s( argv[i] );
    args[i] = s;
  }

  // Establish pair-wise equality between arguments.
  for (int i = 1; i < argc-1; i++) {
    if (args[i] == args[i+1]) {
      std::cout << "Check!" << std::endl;
    }
    else if ( args[i] == "Hey!" ) {
      std::cout << "Huh?" << std::endl;
    }
    else {
      std::cout << "Oops!" << std::endl;
    }
  }

  return 0;
}
