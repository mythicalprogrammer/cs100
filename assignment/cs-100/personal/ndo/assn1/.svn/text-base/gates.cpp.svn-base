//Nguyen Do
//860734448
//ndo

#include <iostream>
#include <string>
#include "gates.h"

int
Gates::useNotGate(){
  if(gateVector.empty()){ // there should only be one value
    return !(storeValueVector[0].value);
  }
  else{ // Gate vector is not empty, there should only be one gate
    if(gateVector[0].getResult()!=-1){
      return gateVector[0].getResult();
    }
    else{
      return gateVector[0].findAnswer();
    }
  }
  return -1;
}

int
Gates::useAndGate(){
  if(gateVector.empty()){
    this->result = storeValueVector[0].value;
    for(int i = 1; i < storeValueVector.size(); i++){// iterate through values
      result = result and storeValueVector[i].value;
    }
    return result;
  }
  else{
    if(storeValueVector.empty()!=true){ // storeValues have values
      this->result = storeValueVector[0].value;
      for(int i = 1; i < storeValueVector.size(); i++){
	result = result and storeValueVector[i].value;
      }
      for(int i = 0; i < gateVector.size(); i++){
	if(gateVector[i].getResult()==-1){
	  result = result and gateVector[i].findAnswer();
	}
	else{
	  result = result and gateVector[i].getResult();
	}
      }
      return result;
    }
    else{ // only gates' values

      if(gateVector[0].getResult()==-1){
	this->result = gateVector[0].findAnswer();
      }
      else{
	this->result = gateVector[0].getResult();
      }
      for(int i = 1; i < gateVector.size(); i++){
	if(gateVector[i].getResult()==-1){
	  result = result and gateVector[i].findAnswer();
	}
	else{
	  result = result and gateVector[i].getResult();
	}
      }
      return result;
    }
  }
  return -1;
}

int
Gates::useOrGate(){
  if(gateVector.empty()){
    this->result = storeValueVector[0].value;
    for(int i = 1; i < storeValueVector.size(); i++){// iterate through values
      result = result and storeValueVector[i].value;
    }
    return result;
  }
  else{
    if(storeValueVector.empty()!=true){ // storeValues have values
      this->result = storeValueVector[0].value;
      for(int i = 1; i < storeValueVector.size(); i++){
	result = result or storeValueVector[i].value;
      }
      for(int i = 0; i < gateVector.size(); i++){
	if(gateVector[i].getResult()==-1){
	  result = result or gateVector[i].findAnswer();
	}
	else{
	  result = result or gateVector[i].getResult();
	}
      }
      return result;
    }
    else{ // only gates' values

      if(gateVector[0].getResult()==-1){
	this->result = gateVector[0].findAnswer();
      }
      else{
	this->result = gateVector[0].getResult();
      }
      for(int i = 1; i < gateVector.size(); i++){
	if(gateVector[i].getResult()==-1){
	  result = result or gateVector[i].findAnswer();
	}
	else{
	  result = result or gateVector[i].getResult();
	}
      }
      return result;
    }
  }
  return -1;
}

Gates::Gates(){
  this->gateName = "";
  this->gateType = "";
  this->gateVector.clear();
  this->storeValueVector.clear();
  this->result = -1;
}

Gates::Gates(string gateName, string gateType){
  Gates(); //start with the initial values
  this->gateName = gateName;
  StringToUpperCase gateTypeUpperCase (gateType);
  this->gateType = gateTypeUpperCase.returnUpperCase();
}

void
Gates::changeName(string gateName){
  this->gateName = gateName;
}

void
Gates::changeType(string gateType){
  this->gateType = ""; // resets the all variables except the name
  this->gateVector.clear();
  this->storeValueVector.clear();
  this->result = -1;
  StringToUpperCase gateTypeUpperCase (gateType);
  this->gateType = gateTypeUpperCase.returnUpperCase();
}

void
Gates::pushValue(StoreValues aValue){
  storeValueVector.push_back(aValue);
}

void
Gates::pushGate(Gates aGate){
  gateVector.push_back(aGate);
}

int
Gates::findAnswer(){
  if(gateType=="NOT"){
    this->result = useNotGate();
    return result;
  }
  else if(gateType=="AND"){
    this->result = useAndGate();
    return result;
  }
  else if(gateType=="OR"){
    this->result = useOrGate();
    return result;
  }
  return -1;
}

void
Gates::resetGate(){
  this->gateVector.clear();
  this->storeValueVector.clear();
  this->result = -1;
}

//=====================================================================
// Accessors

string
Gates::getName(){
  return gateName;
}

string
Gates::getType(){
  return gateType;
}

int
Gates::getResult(){
  return result;
}
