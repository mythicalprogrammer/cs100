#include <iostream>
#include <string>

#include "parse.h"

using namespace std;




int main()
{

string name;
cout<<" file name : "<<endl;
cin >> name;
parse h(name);

h.parse_it();



return 0;
}


