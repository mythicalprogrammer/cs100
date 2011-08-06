class Wire;
#ifndef _OR_H_
#define _OR_H_
#include <iostream>
#include "gate.h"
#include "wire.h"
using namespace std;

class OR:public Gate
{
friend class Wire;

public:
OR();
OR(string);
void gateOutput();//will have wires as left and right and if its an output wire it will just call gateOutput() again
void gateOutput(Wire*);
};
#endif 
