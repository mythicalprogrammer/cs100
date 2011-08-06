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

#include <iostream>
#include "gate.h"
#include "wire.h"
using namespace std;

Gate::Gate()
{
  
  gateName="";
  wireZero=NULL;
  wireOne=NULL;
  wireOut=NULL;

}
Gate::Gate(string nameInput)
{
  
  gateName=nameInput;
  wireZero=NULL;
  wireOne=NULL;
  wireOut=NULL;

}
Gate::~Gate(){


}


string Gate::get_gateName()
{
  return gateName;
}
void Gate::setWireZero(Wire* wireInput)
{
  wireZero=wireInput;
}

void Gate::setWireOne(Wire *wireInput)
{
  wireOne=wireInput;
}

void Gate::setWireOut(Wire *wireInput)
{
  wireOut=wireInput;
}

Wire * Gate::get_ZeroWire()
{
return wireZero;
}
Wire * Gate::get_OneWire()
{
return wireOne;
}
Wire * Gate::get_OutputWire()
{
return wireOut;
}

/*
void Gate::gateOutput()
//will have wires as left and
// right and if its an output
// wire it will just call
// gateOutput() again
{
//will check the wire types and 
//if theire external then its
// cool and does its thing but
// if not
  gateOutput(wireOut);
}

void Gate::gateOutput(Wire *wireOutput)
//will have wires as left and 
//right and if its an output
// wire it will just call 
//gateOutput() again
{
//will check the wire types 
//and if theire external then
// its cool and does its thing
// but if not
//one for each type of gate
		
  if(wireOutput->get_sourceGate()=="AND")
	  {
     if(wireZero->get_type()=="internal")
     		{
     		  Gate *gateRecursive=wireZero->get_sourceGatepointer();
     		  gateRecursive->gateOutput(wireZero);
     		}
     if(wireOne->get_type()=="internal")
     		{
     		  Gate *gateRecursive2=wireOne->get_sourceGatepointer();
     		  gateRecursive2->gateOutput(wireOne);
     		
     		}
     	if(wireZero->get_charge() and wireOne->get_charge())
     		{
     		  wireOutput->set_charge(true);
     		}
     	else
     		{
          wireOutput->set_charge(false);   		
     		}	
	  }

  else if(wireOutput->get_sourceGate()=="NOT")
	  {
	  	if(wireZero->get_type()=="internal")
     		{
     		  Gate *gateRecursive3=wireZero->get_sourceGatepointer();
     		  gateRecursive3->gateOutput(wireZero);
     		}

     	if(wireZero->get_charge()==false)
     		{
     		  wireOutput->set_charge(true);
     		}
     	else
     		{
          wireOutput->set_charge(false);   		
     		}	
	  }
	
  else if(wireOutput->get_sourceGate()=="OR")
	  {
	  		if(wireZero->get_type()=="internal")
     		{
     		  Gate *gateRecursive5=wireZero->get_sourceGatepointer();
     		  gateRecursive5->gateOutput(wireZero);
     		}
     if(wireOne->get_type()=="internal")
     		{
     		  Gate *gateRecursive6=wireOne->get_sourceGatepointer();
     		  gateRecursive6->gateOutput(wireOne);
     		
     		}

     	if(wireZero->get_charge() or wireOne->get_charge())
     		{
     		  wireOutput->set_charge(true);
     		}
     	else
     		{
          wireOutput->set_charge(false);   		
     		}	
	  }
}
*/
