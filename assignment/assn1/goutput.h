#ifndef GOUTPUT_H_
#define GOUTPUT_H_


#include<iostream>

using namespace std;

class goutput
{
  public:

  goutput()
  {
   this->val = false; 
   this->name = name;
  }

  goutput(bool val)
  {
    this->val = val;
  }

  bool value()
  {
    return this->val;
  }  
  void set_name (char name)
  {
    this->name = name;
  }
  char get_name()
  {
    return this->name;
  }
  private:
  bool val;
  char name;

};

#endif /*GOUTPUT_H_*/
