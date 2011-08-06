#include <iostream>
#include <string>

#include "parse.h"

using namespace std;




int main(int argc, char *argv[])
{

if(argc < 2)
{
cout<<"ERROR! Please supply filename."<<endl;
return 0;
}
string name = argv[1];

parse h(name);

h.parse_it();



return 0;
}


