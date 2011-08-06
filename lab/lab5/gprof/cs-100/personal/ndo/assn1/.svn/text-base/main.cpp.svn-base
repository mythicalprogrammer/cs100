//Nguyen Do
//860734448
//ndo

#include <iostream>
#include <string>
#include "parser.h"

using namespace std;

int main(int argc, char *argv[])
{

  /**
   * Check if executable was used correctly
   * If not:
   * print error message
   * show correct usage
   * exit program
   */
  if(argc!=2){
    cout << "Incorrect usage. Format is: a.out filename.txt";
    return -1;
  }

  string theFile = argv[1];

  Parser theParse;
  theParse.parseFile(theFile);
  theParse.createTable();

  return 0;
}
