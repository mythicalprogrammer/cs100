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


#include "wire.h"
#include "gate.h"
#include <iostream>

using namespace std;

Wire::Wire() : wireName(""), wireType(""), wireCharge(false),
	       intoGate(0), outofGate(0),disable(false)
{
}

Wire::Wire(string nameInput,string typeInput) : wireName(""), wireType(""),
                               wireCharge(false), intoGate(0), outofGate(0),disable(false)
{
  wireName=nameInput;
  wireType=typeInput;
}

Wire::Wire(const Wire& temp) : wireName(""), wireType(""), wireCharge(false),
	       intoGate(0), outofGate(0),disable(false) 
{
  this->wireName = temp.wireName;
  this->wireType = temp.wireType;
  this->wireCharge = temp.wireCharge;
  this->intoGate = temp.intoGate;
  this->outofGate = temp.outofGate;
  this->disable = temp.disable;
}

Wire::~Wire()
{

}

Wire& Wire::operator=(Wire temp)
{
  this->wireName = temp.wireName;
  this->wireType = temp.wireType;
  this->wireCharge = temp.wireCharge;
  this->intoGate = temp.intoGate;
  this->outofGate = temp.outofGate;
  this->disable = temp.disable;
  return *this;
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


string Wire::get_destinationName()
{
  if(intoGate)
  {
    /*Post-condition DBC*/
    if(!disable)
    {
    ENSURE((intoGate->get_gateName())!="");
    }
    return intoGate->get_gateName();
  }
  else
  exit(1);
}  

      
string Wire::get_sourceName()   
{
  if(outofGate)
  {
    /*Post-condition DBC*/
    if(!disable)
    {
    ENSURE((outofGate->get_gateName())!="");
    }
    return outofGate->get_gateName();
  }
  else
  exit(1);

}     

void Wire::enableErrorCheck()
{
disable=false;
}
void Wire::disableErrorCheck()
{
disable=true;
}

