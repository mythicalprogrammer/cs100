/**
 * \ginput.h
 * \author Quoc Anh Doan
 * \SID: 860759993
 * \Login: qdoan
 * \Date: April 14, 2008
 */
#ifndef GINPUT_H_
#define GINPUT_H_


#include<iostream>

using namespace std;

/**
 * The class ginput
 * Description: This class holds the gate input values
 */
class ginput
{
  public:

  /** The Constructor. */
  ginput()
  {
   this->val = false; 
   this->name = name;
  }

  /** The Constructor with parameter. */
  ginput(bool val)
  {
    this->val = val;
  }

  /**
     Return the value

     \param val A bool 
     \return Returns a bool
  */
  bool value()
  {
    return this->val;
  }  

  /**
     Set the value

     \param val A bool parameter 
  */
  void set_value(bool value)
  {
    this->val = value;
  }

  /**
     Set the name

     \param name A string parameter
  */
  void set_name (char name)
  {
    this->name = name;
  }

  /**
     Return name

     \return Returns a char 
  */
  char get_name()
  {
    return this->name;
  }
  private:
  bool val; ///< This holds the input value
  char name; ///< This holds the input name

};

#endif /*GINPUT_H_*/
