#ifndef GWIRE_H_
#define GWIRE_H_


#include<iostream>
#include<string>

using namespace std;

class gwire
{
  public:

  gwire()
  {
    from = ' ';
    to = ' ';
    name = ' ';
    type = "unknown";
  } 

  gwire(char wire_name)
  {
    this->name = wire_name;
  }

  void set_to (char t_to)
  {
    this->to = t_to;
  }
 
  void set_from (char t_from)
  {
    this->from = t_from;
  }

  void set_type (string t_type)
  {
    this->type = t_type;
  }
  
  void set_name(char t_name)
  {
    this->name = t_name;
  }

  char get_to()
  {
    return this->to;
  }

  char get_from()
  {
    return this->from;
  }

  char get_name()
  {
    return this->name;
  }

  string get_type()
  {
    return this->type;
  }

  private:
  char from;
  char to;
  char name;
  string type;

};

#endif /*GWIRE_H_*/
