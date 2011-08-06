// Course:            CS 100
// Group:             Deviant Programmers
// Lecture Section:   1
// Lab time:					Friday 11-2 pm
// Date completed:    4/28/08
// Names:             Jay Novilla
//                    Quoc Doan
//                    Keith Ailshie
//                    Nguyen Do
// ID Number:         Jay Novilla:860802932
//                    Quoc Doan:860759993
//                    Keith Ailshie:860816418
//                    Nguyen Do:860734448
// Login:             jnovilla
//                    qdoan
//                    ndo
//                    kailshie
// Project:						2
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
