//Nguyen Do
//860734448
//ndo

#ifndef __STRINGTOUPPERCASE_H
#define __STRINGTOUPPERCASE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

class StringToUpperCase{

 private:

  string result;
  StringToUpperCase();
  void convertToUpperCase(string theString);

 public:

  StringToUpperCase(string theString);
  string returnUpperCase();
};

#endif
