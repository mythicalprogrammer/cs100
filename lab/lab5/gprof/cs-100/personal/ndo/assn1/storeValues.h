//Nguyen Do
//860734448
//ndo

#ifndef __STOREVALUES_H
#define __STOREVALUES_H

#include <string>

using namespace std;

class StoreValues{

 public:

  string name;
  int value;
  string type; // IN or OUT
  string gateBeforeOut;

  StoreValues(){
    name = "";
    value = 0;
  }

};

#endif
