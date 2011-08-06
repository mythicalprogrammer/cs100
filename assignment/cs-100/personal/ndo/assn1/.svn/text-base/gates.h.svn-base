//Nguyen Do
//860734448
//ndo

#ifndef __GATES_H
#define __GATES_H

#include <iostream>
#include <string>
#include <vector>
#include "storeValues.h"
#include "stringToUpperCase.h"

using namespace std;

class Gates{

 private:

  /// Variables
  string gateName;
  string gateType;

  vector<Gates> gateVector;
  vector<StoreValues> storeValueVector;

  int result;

  ///Recrusive Gate Functions
  int useNotGate(); // Returns the !(store
  int useAndGate();
  int useOrGate();

 public:

  ///Constructors
  Gates();
  Gates(string,string);

  ///Mutators
  void changeName(string); ///< Chantes the name of the gate
  void changeType(string); ///< Changes the type of the gate: "AND" "OR" "NOT"
  /**
    * Whenever the type is changed, the result is set to -1.
    */
  void pushValue(StoreValues); ///< Pushes a StoreValues input into vector
  void pushGate(Gates); ///< Pushes a Gates input into vector
  int findAnswer(); ///< Finds the answer for the Gate
  void resetGate();

  ///Accessors
  string getName(); ///< Returns the name of the Gate
  string getType(); ///< Returns the type of the Gate
  int getResult(); ///< Returns the answer (returns -1 if answer not found yet)
};

#endif
