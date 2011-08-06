#include "parser.h"
#include <iostream>
#include <string>

 string TYPE = "UNKNOWN";

 parser::parser()
 { 
  this->file = "";
 }//end default constructor

 parser::parser(string file)
 {
  this->file = file;
 }//end overload constructor 
