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





void OR::gateOutput(Wire* wireOutput)
{
  /*Pre-condition DBC*/
  if(!disable)
  {
    //cout << "disable was off in the AND gates;";
    //cout << wireZero << "," << wireOne << "," << wireOut << endl;
    //REQUIRE(wireZero != NULL and wireOne != NULL and wireOut != NULL);
     REQUIRE(wireZero != NULL);
     REQUIRE(wireOne != NULL );
     REQUIRE(wireOut != NULL);
    REQUIRE(wireZero->get_type()=="internal" or wireZero->get_type()=="external");
    REQUIRE(wireZero->get_charge()==false or wireZero->get_charge()==true);
  }
	if(wireZero->get_type()=="internal")
  {
    if(!calculated)
    {
      if(!traversed)
      {
        traversed=true;
      }
      else
      {
        if(!disable)
        {
          REQUIRE(!traversed);      
        }    
        exit(-1);
      }
    }  		
		/*Post-condition DBC*/
		if(!disable)
    {
    //cout << "or!\n";
     // ENSURE((wireZero->get_sourceGatepointer())!=NULL);
      
    }
      Gate *gateRecursive5=wireZero->get_sourceGatepointer();
     	gateRecursive5->gateOutput(wireZero);
     	calculated=true;
    }
    if(wireOne->get_type()=="internal")
    {
      if(!calculated)
    {
      if(!traversed)
      {
        traversed=true;
      }
      else
      {
        if(!disable)
        {
          REQUIRE(!traversed);      
        }    
        exit(-1);
      }
    }  		
		/*Post-condition DBC*/  
    if(!disable)
    {
      //ENSURE((wireZero->get_sourceGatepointer())!=NULL);
    }
    Gate *gateRecursive6=wireOne->get_sourceGatepointer();
    gateRecursive6->gateOutput(wireOne);
  	calculated=true;
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

