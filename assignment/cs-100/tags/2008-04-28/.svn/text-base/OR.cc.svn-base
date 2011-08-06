
#include <iostream>
#include "OR.h"
#include "wire.h"
using namespace std;

OR::OR():Gate(){
   /*
   gateName="";
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
   */
}
OR::OR(string inputName):Gate(inputName){

   /*
   gateName=inputName;
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
   */
}


void OR::gateOutput(){

 gateOutput(wireOut);
}//will have wires as left and right
// and if its an output wire it will
// just call gateOutput() again
void OR::gateOutput(Wire* wireOutput){
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

