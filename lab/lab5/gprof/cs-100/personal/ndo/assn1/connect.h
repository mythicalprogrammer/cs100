//Nguyen Do
//860734448
//ndo

#ifndef __CONNECT_H
#define __CONNECT_H

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "gates.h"
#include "wires.h"
#include "storeValues.h"
#include "stringToUpperCase.h"

using namespace std;

class Connect{

 private:

  vector<StoreValues> theValues;
  vector<Gates> theGates;
  vector<Wires> theWires;
  vector<StoreValues> theFinalResults;

 public:

  Connect(){
    theValues.clear();
    theGates.clear();
    theWires.clear();
  }

  int searchValues(string theName){
    for(int i = 0; i<theValues.size(); i++){
      if(theValues[i].name==theName){
	return i;
      }
    }
    return -1;
  }

  int searchGates(string theName){
    for(int i = 0; i<theGates.size(); i++){
      if(theGates[i].gateName==theName){
	return i;
      }
    }
    return -1;
  }

  // ===============
  // value pushing

  void pushStoreValue(string name, string type){
    StoreValues tempValue;
    tempValue.name = name;
    tempValue.type = type;
    theValues.push_back(tempValue);
  }

  void addValueNum(string valueName, int valueNum){
    int i = searchValues(valueName); //find the index
    theValues[i].value = valueNum;
  }

  //===============
  // gate pushing

  void pushGate(string name, string type){
    Gates tempGate (name, type);
    theGates.push_back(tempGate);
  } 

  //=============== 
  // wire pushing

  void pushWire(string from, string to){
    Wires tempWire;
    tempWire.from = from;
    tempWire.to = to;
    theWires.push_back(tempWire);
  }

  void createTable(){


    // adds value to a b c
    for(int i = 0; i<theValues.size(); i++){
      if(theValues[i].type=="IN"){
	theValues[i].value = 0;
      }
    }
	//-----------------

    for(int i = 0; i<theWires.size(); i++){
	int index1 = (theWires[i].from).find("(");
	int index2 = (theWires[i].to).find("(");
	if(index1==-1 and index2==-1){
	  int indexTo = searchValues(theWires[i].to);
	  int indexFrom = searchValues(theWires[i].from);
	  theValues[indexTo].value = theValues[indexFrom].value;
	}
    }
    for(int i = 0; i<theWires.size(); i++){
      int index1 = (theWires[i].from).find("(");
      int index2 = (theWires[i].to).find("(");
      if(index1==-1 and index2!=-1){
	string tempGateName = (theWires[i].to).substr(0,index2);
	int indexTo = searchGates(tempGateName);
	int indexFrom = searchValues(theWires[i].from);
	theGates[indexTo].pushValue(theValues[indexFrom]);
      }
    }
    for(int i = 0; i<theWires.size(); i++){
      int index1 = (theWires[i].from).find("(");
      int index2 = (theWires[i].to).find("(");
      if(index1!=-1 and index2!=-1){
	string tempGateNameFrom = (theWires[i].from).substr(0,index1);
	string tempGateNameTo = (theWires[i].to).substr(0,index2);
	int indexTo = searchGates(tempGateNameTo);
	int indexFrom = searchValues(tempGateNameTo);
	theGates[indexTo].pushGate(theGates[indexFrom]);
      }
    }
    for(int i = 0; i<theWires.size(); i++){
      int index1 = (theWires[i].from).find("(");
      int index2 = (theWires[i].to).find("(");
      if(index1!=-1 and index2==-1){
	string tempGateName = (theWires[i].to).substr(0,index1);
	int indexTo = searchValues(theWires[i].to);
	int indexFrom = searchGates(tempGateName);
	theValues[indexTo].value = theGates[indexFrom].getResult();

	// add gate name to recurse on
	theValues[indexTo].gateBeforeOut = theGates[indexFrom].getName();
      }
    }// end of for loops for wires
    // for loop for outputs
    for(int i = 0; i<theValues.size(); i++){
      if(theValues[i].type=="OUT"){
	if(theValues[i].value!=-1){
	  theFinalResults.push_back(theValues[i]);
	}
	else{ // there is a gate
	  theValues[i].value = (theValues[i].gateBeforeOut).findAnswer();
	  theFinalResults.push_back(theValues[i]);
	}
      }
    }// end of one table row
    // need to reset gate values HERE
    for(int i = 0; i<theGates.size(); i++){
      theGates[i].resetGate();
    }
  }
  

};

#endif
