/**
 * \gwire.h
 * \author Quoc Anh Doan
 * \SID: 860759993
 * \Login: qdoan
 * \Date: April 14, 2008
 */

#ifndef GWIRE_H_
#define GWIRE_H_


#include<iostream>
#include<string>

using namespace std;
/**
 * The class gwire
 * Description: This class creates and connects the ending 
 *              of the wires
 */
class gwire
{
  public:

  /** The Constructor. */
  gwire()
  {
    from = ' ';
    to = ' ';
    name = ' ';
    type = "unknown";
  } 

  /** The Constructor with parameters. */
  gwire(char wire_name)
  {
    this->name = wire_name;
  }


  /**
     Set the to value

     \param to A char parameter 
  */
  void set_to (char t_to)
  {
    this->to = t_to;
  }
 
  /**
     Set the from value

     \param from A char parameter 
  */
  void set_from (char t_from)
  {
    this->from = t_from;
  }

  /**
     Set the type

     \param type A string parameter 
  */
  void set_type (string t_type)
  {
    this->type = t_type;
  }
  
  /**
     Set the name

     \param name A string parameter 
  */
  void set_name(char t_name)
  {
    this->name = t_name;
  }

  /**
     Returns to 

     \return Returns a char 
  */
  char get_to()
  {
    return this->to;
  }

  /**
     Returns from

     \return Returns a char 
  */
  char get_from()
  {
    return this->from;
  }

  /**
     Returns name

     \return Returns a string
  */
  char get_name()
  {
    return this->name;
  }

  /**
     Returns type

     \return Returns a string
  */
  string get_type()
  {
    return this->type;
  }

  private:
  char from; ///< This holds the from (the ending value of the wire)
  char to; ///< This holds the to (the ending value of the wire)
  char name;///< This holds the name of the wire value
  string type;///< This holds the input type value (which can be: input, output, internal)

};

#endif /*GWIRE_H_*/
