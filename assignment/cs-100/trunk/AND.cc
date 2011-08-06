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

AND::AND() : Gate()
{
  gateType = "AND";
}

AND::AND(string inputName) : Gate(inputName)
{
  gateType = "AND";
}

//will have wires as left and right and
// if its an output wire it will just call
// gateOutput() again
void AND::gateOutput()
{
  //will check the wire types and if theire 
  //external then its cool and does its thing 
  //but if not
  gateOutput(wireOut);
}

void AND::gateOutput(Wire *wireOutput)
{
  //will have wires as left and right and if 
  //its an output wire it will just call 
  //gateOutput() again
  //will check the wire types and if theire 
  //external then its cool and does its thing
  //but if not
  //one for each type of gate

  /*Pre-condition DBC*/
  if(!disable)
  {
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

    Gate *gateRecursive=wireZero->get_sourceGatepointer();
    gateRecursive->gateOutput(wireZero);
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
     		
    Gate *gateRecursive2=wireOne->get_sourceGatepointer();
    gateRecursive2->gateOutput(wireOne);
    calculated=true;
  }	
  
  //calculations
  if(wireZero->get_charge() and wireOne->get_charge())
  {
    wireOutput->set_charge(true);
  }
  else
  {
    wireOutput->set_charge(false);   		
  }	  
}
