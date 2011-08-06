//Nguyen Do
//860734448
//ndo

#include "stringToUpperCase.h"

StringToUpperCase::StringToUpperCase(){
  this->result ="";
}

void
StringToUpperCase::convertToUpperCase(string theString){
  for(int i = 0; i<theString.size(); i++){
    theString[i] = toupper(theString[i]);
  }
  this->result = theString;
}

StringToUpperCase::StringToUpperCase(string theString){
  StringToUpperCase();
  convertToUpperCase(theString);
}

string
StringToUpperCase::returnUpperCase(){
  return result;
}

