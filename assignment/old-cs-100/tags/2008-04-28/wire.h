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

class Gate;
#ifndef _WIRE_H_
#define _WIRE_H_

#include <iostream>
#include "gate.h"
using namespace std;

class Wire
{
friend class Gate;
protected:
  string wireName;
  string wireType;//either external or internal
  bool wireCharge;
  Gate * intoGate;
  Gate * outofGate;
public:
Wire();
Wire(string,string);
void set_charge(bool);
void set_name(string);
void set_type(string);
void set_destinationGate(Gate*);
void set_sourceGate(Gate*);
//these gates are for finding the gates they go out of and into during the output phase
bool get_charge();
Gate * get_sourceGatepointer();
string get_name();
string get_type();
};
#endif
