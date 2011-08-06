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
#include "object.h"

using namespace std;

Gate::Gate() : gateName(""), wireZero(0), wireOne(0), wireOut(0), disable(false),
               traversed (false),calculated(false), gateType("")
{
}

Gate::Gate(const Gate& temp) : gateName(""), wireZero(0), wireOne(0),
			                         wireOut(0),disable(false), traversed(false),
			                         calculated(false), gateType("")
{
  this->gateName = temp.gateName;
  this->wireZero = temp.wireZero;
  this->wireOne = temp.wireOne;
  this->wireOut = temp.wireOut;
  this->disable = temp.disable; 
  this->gateType = temp.gateType;
}

Gate::Gate(string nameInput) : gateName(""), wireZero(0), wireOne(0), 
			                         wireOut(0), disable(false), traversed(false), 
			                         calculated(false), gateType("")
{  
  gateName=nameInput;
}

Gate::~Gate()
{
}


Gate& Gate::operator=(Gate &temp)
{
  //return new Gate(temp);
  this->gateName = temp.gateName;
  this->wireZero = temp.wireZero;
  this->wireOne = temp.wireOne;
  this->wireOut = temp.wireOut;
  this->disable = temp.disable;
  this->traversed = temp.traversed;
  this->calculated = temp.calculated; 
  return *this; 
}

string Gate::get_gateName()
{
  return gateName;
}

string Gate::get_gateType()
{
  return gateType;
}

void Gate::setWireZero(Wire* wireInput)
{ 
  /*Pre-condition DBC*//*
  if(!disable)
  {
    REQUIRE(wireZero==NULL);
  }
  */
  wireZero=wireInput;
}

void Gate::setWireOne(Wire *wireInput)
{
  /*Pre-condition DBC*//*
  if(!disable)
  {
    REQUIRE(wireOne==NULL);
  }
  */
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

bool Gate::checkOutWire()
{
 if(wireOut)
 {
  return true;
 }
 else 
 return false;
}

void Gate::enableErrorCheck()
{
  disable=false;
}

void Gate::disableErrorCheck()
{
  disable=true;
}
