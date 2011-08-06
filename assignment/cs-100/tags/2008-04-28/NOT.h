class Wire;
#ifndef _NOT_H_
#define _NOT_H_
#include <iostream>
#include "gate.h"
#include "wire.h"
using namespace std;

class NOT:public Gate
{
friend class Wire;

public:
NOT();
NOT(string);
void gateOutput();//will have wires as left and right and if its an output wire it will just call gateOutput() again
void gateOutput(Wire*);
};
 #endif 
