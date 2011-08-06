
#include <iostream>
#include "NOT.h"
#include "wire.h"
using namespace std;

NOT::NOT():Gate(){
   /*
   gateName="";
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
   */
}
NOT::NOT(string inputName):Gate(inputName){

   /*
   gateName=inputName;
   wireZero=NULL;
   wireOne=NULL;
   wireOut=NULL;
   */
}


void NOT::gateOutput()
//will have wires as left and right and if its an 
//output wire it will just call gateOutput() again
{
//will check the wire types and if theire external 
//then its cool and does its thing but if not
  gateOutput(wireOut);
}

void NOT::gateOutput(Wire *wireOutput)
//will have wires as left and right and if its an 
//output wire it will just call gateOutput() again
{
//will check the wire types and if theire external
// then its cool and does its thing but if not
//one for each type of gate
	

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

