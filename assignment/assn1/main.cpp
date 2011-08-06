#include <iostream>
#include <string>
#include <fstream>
#include "parser_gate.h"

using namespace std;




int main()
{
  string file_name;


  cout<<"name file: "<<endl;
  cin>>file_name;

  parser_gate h(file_name);
 //h.set_filename(file_name);
  //h.parse_it();

return 0;
}



