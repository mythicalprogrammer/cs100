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

#include "wire.h"
#include "gate.h"
#include <iostream>
using namespace std;
Wire::Wire()
{
  wireCharge=false;
  wireType="";
  wireName="";
  intoGate=NULL;
  outofGate=NULL;
}

Wire::Wire(string nameInput,string typeInput)
{
  wireName=nameInput;
  wireType=typeInput;
}

void Wire::set_charge(bool inputCharge)
{
  wireCharge=inputCharge;
}
bool Wire::get_charge()
{
  return wireCharge;
}

string Wire::get_name()
{
  return wireName;
}

string Wire::get_type()
{
  return wireType;
}

string Wire::get_sourceGate()
{
return outofGate->get_gateType();
}

Gate* Wire::get_sourceGatepointer()
{
return outofGate;
}

void Wire::set_name(string inputName)
{
  wireName=inputName;
}

void Wire::set_type(string typeInput)
{
  wireType=typeInput;
}
void Wire::set_destinationGate(Gate * inGate)
{
  intoGate=inGate;
}
void Wire::set_sourceGate(Gate * outGate)
{
  outofGate=outGate;
}
/*
Gate * intoGate;
Gate * outofGate;
*/

//these gates are for finding the gates they go out of and into during the output phase
