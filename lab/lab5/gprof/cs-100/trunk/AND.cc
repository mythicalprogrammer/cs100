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
#include "AND.h"
#include "wire.h"
using namespace std;

AND::AND():Gate(){
/*   
   gateName="";
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
*/

}
AND::AND(string inputName):Gate(inputName)
{
   /*
   gateName=inputName;
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
*/
}


void AND::gateOutput()
//will have wires as left and right and
// if its an output wire it will just call
// gateOutput() again
{
//will check the wire types and if theire 
//external then its cool and does its thing 
//but if not
  gateOutput(wireOut);
}

void AND::gateOutput(Wire *wireOutput)
//will have wires as left and right and if 
//its an output wire it will just call 
//gateOutput() again
{
//will check the wire types and if theire 
//external then its cool and does its thing
//but if not
//one for each type of gate
	
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
