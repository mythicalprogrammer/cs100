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
	
  //get_type : internal, external
  //get_charge : 0,1

  /*Pre-condition DBC*/
  REQUIRE(wireZero != NULL and wireOut != NULL);
  REQUIRE(wireZero->get_type()=="internal" or wireZero->get_type()=="external");
  REQUIRE(wireZero->get_charge()==false or wireZero->get_charge()==true);

	  	if(wireZero->get_type()=="internal")
     		{
		  /*Post-condition DBC*/
                  ENSURE((wireZero->get_sourceGatepointer())!=NULL);

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

