
// Course:            CS 100

// Lecture Section:   1
// Lab time:					Friday 11-2 pm
// Date completed:    
// First Name:        Jay
// Last Name:         Novilla
// ID Number:         860802932
// Email address:     jay-r.novilla@email.ucr.edu
// Project:						1
// =======================================================================**
class Wire;
#ifndef _GATE_H_
#define _GATE_H_

#include <iostream>
#include "wire.h"
using namespace std;

class Gate
{
friend class Wire;
protected:
  string gateName;
  Wire * wireZero;
  Wire * wireOne;
  Wire * wireOut;
public:
Gate();
virtual ~Gate();
Gate(string);
string get_gateName();
void setWireZero(Wire*);
void setWireOne(Wire*);
void setWireOut(Wire*);
Wire * get_ZeroWire();
Wire * get_OneWire();
Wire * get_OutputWire();
virtual void gateOutput() =0;//will have wires as left and right and if its an output wire it will just call gateOutput() again
virtual void gateOutput(Wire*) =0;
};
#endif
