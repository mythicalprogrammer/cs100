class Wire;
#ifndef _AND_H_
#define _AND_H_
#include <iostream>
#include "gate.h"
#include "wire.h"
using namespace std;

class AND:public Gate
{
friend class Wire;
public:
AND();
AND(string);
void gateOutput();//will have wires as left and right and if its an output wire it will just call gateOutput() again
void gateOutput(Wire*);
};
#endif
