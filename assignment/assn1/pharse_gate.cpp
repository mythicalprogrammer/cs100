#include "parser_gate.h"
#include <iostream>
#include <string>

 string TYPE = "UNKNOWN";

 parser_gate::parser_gate()
 { 
  this->file = "";
 }//end default constructor

 parser_gate::parser_gate(string file)
 {
  this->file = file;
 }//end overload constructor 
