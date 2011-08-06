/**
 * \goutput.h
 * \author Quoc Anh Doan
 * \SID: 860759993
 * \Login: qdoan
 * \Date: April 14, 2008
 */
#ifndef GOUTPUT_H_
#define GOUTPUT_H_


#include<iostream>

using namespace std;

/**
 * The class goutput
 * Description: This class holds the gate output values
 */

class goutput
{
  public:

  /** The Constructor. */
  goutput()
  {
   this->val = false; 
   this->name = name;
  }

  /** The Constructor with parameter. */
  goutput(bool val)
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
     Set the name

     \param name A string paramater
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
  bool val; ///< This holds the output value
  char name; ///< This holds the output name

};

#endif /*GOUTPUT_H_*/
