#ifndef GATE_H_
#define GATE_H_

#include<string>
#include<iostream>
#include <fstream>
#include <vector>
#include "ginput.h"


class gate
{
  public:

   gate()
   {
     this->gate_name = ' ';
     this->type = "UNKNOWN";
     this->output = 0;
  
     this->internal = false;
     this->last_gate = false;
     this->dirtyBit = false;
   }

  gate(char name)
   {
     this->gate_name = name;
     this->type = "UNKNOWN";
     this->output = 0;

     this->internal = false;
     this->last_gate = false;
     this->dirtyBit = false;
   } 

   void set_type(string type)
   {
     this->type = type;
   }

   void add_input(ginput in)
   {
     input_array.push_back(in);
   }

   char get_name()
   {
     return this->gate_name;
   } 

   void set_depend(char d_name)
   {
     this->depend_goutput.push_back(d_name);
     internal = true;
   }
  
   char get_depend()
   {
    return this->depend_goutput[0];
   }

   char get_depend2()
   {
    return this->depend_goutput[1];
   }

   bool depend_status()
   {
     return internal;
   }

   void set_output(char output_name)
   {
     this->output_name = output_name;
     this->last_gate = true;
   }

   bool check_last_gate()
   {
     
     return this->last_gate;
   }

   bool output_value()
   {
     return this->output;
   }

   void set_dirtybit(bool bit)
   {
     this->dirtyBit = bit;
   }

   void set_output_value(bool value, bool value2)
   {
    
    if(input_array.size() >= 2)
    { 
       this->output = input_array[0].value();

       if(this->type == "OR")
      	{for(int i = 1; i < input_array.size(); ++i)
          this->output = this->output | input_array[i].value();}
       else if(this->type == "AND")
        {for(int i = 1; i < input_array.size(); ++i)
          this->output = this->output & input_array[i].value();}
   
       
    }

    else if(input_array.size() == 1)
    {
      if(this->type == "OR")
       this->output = input_array[0].value() | value;
      else if(this->type == "AND")
        this->output = input_array[0].value() & value;
    }

    else if(input_array.size() == 0)
    {
      if(this->type == "OR")
        this->output = value2 | value;
      else if(this->type == "AND")
        this->output = value2 & value;
    }
   
       this->dirtyBit = true;
   }

   void print_inputs()
   {
     for(int i = 0; i < input_array.size(); ++i)
     {
       cout<<input_array[i].get_name() << " ";
     }
   }

   bool get_dirty()
   {
     return dirtyBit;
   }
  
   void set_input(char t_input, bool t_value)
   {
     for(int i = 0; i < input_array.size(); ++i)
     {
       if(input_array[i].get_name() == t_input)
        input_array[i].set_value(t_value);
     }
   }

   int input_size()
   {
    return input_array.size();
   } 

  private:
   char gate_name;
   string type;
   vector<ginput> input_array;
   bool output;
   char output_name;
   vector<char> depend_goutput;
   bool internal;
   bool last_gate;
   bool dirtyBit;
};

#endif /*GATE_H_*/
