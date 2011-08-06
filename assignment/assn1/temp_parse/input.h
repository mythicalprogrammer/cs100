#ifndef INPUT_H_
#define INPUT_H_

#include<string>
#include<iostream>
#include <fstream>

class input
{
  public:

  input()
  {
   this->a = false; 
  }

  input(bool a)
  {
    this->a = a;
  }

  bool value()
  {
   return this->a;
  }  

  private:
  bool a;

};

#endif /*INPUT_H_*/
