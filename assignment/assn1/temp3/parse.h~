/**
 * \parse.h
 * \author Quoc Anh Doan
 * \SID: 860759993
 * \Login: qdoan
 * \Date: April 14, 2008
 */
#ifndef PARSE_H_
#define PARSE_H_

#include <iostream>
#include <string>
#include <fstream>
#include "gate.h"
#include "ginput.h"
#include "goutput.h"
#include "gwire.h"
#include<vector>
#include <list>
#include <math.h>
#include<iostream>

string TYPE = "UNKNOWN";


using namespace std;
/**
 * The class parsed
 * Description: This class creates and connects the ending 
 *              of the wires
 */
class parse
{
  public:

  /** The Constructor. */
  parse()
  {
   this->filename = " ";
  }
  /** The Constructor with parameter. */
  parse(string filename)
  {
   this->filename = filename;
  }


  /**
     Return filename

     \return Returns the text file name
  */
  string get_filename()
  {
   return this->filename;
  }

  /**
     This function will parse the whole file
     it also does the tables

  */
  void parse_it()
  {
    string temp = "";
    string text = "";
  int size_text = 0;
  ifstream infile; 
  char c = ' ';
 
  

  //OPEN TEXT FILE
  infile.open(filename.c_str());


  while(infile)
  {
     
    if (infile.eof())
       break;

    infile.get(c);
    text += c;
    size_text++;

  }//end while

 
   int i = 0;
   temp ="";
   bool ignore = false;


  while(i < size_text)
  {
    string input_w = "INPUT";
    string intern_w = "INTERNAL";
    string output_w = "OUTPUT";
    string wire_w = "WIRES";
    size_t found = -1;



    /*check each lines*/

    if(text[i] == '#')
    {
      ignore = true;
    }//end if
    while(text[i] != '\n' ) // while c is not a char
    {
      temp += text[i];
      ++i;
    }//end while

     if(ignore == true)
     {
       found=temp.find(wire_w);
       if(found!=string::npos)
       {
         found=temp.find(input_w);
      	 if(found!=string::npos)
         TYPE = "INPUT";

         found=temp.find(output_w);
         if(found!=string::npos)
         TYPE = "OUTPUT";

         found=temp.find(intern_w);
         if(found!=string::npos)
         TYPE = "INTERNAL";
       }//end if
     }//end if

     if(ignore == false)
     check(temp);// CEHCK;

 
   ++i;
   temp="";
   ignore = false;
 } //end while
 
  put_gate();
 
  make_circuit();

   infile.close(); // close file
}// end parse_it function

/**
  The check function parse gates, wires, and inputs & outputs. 
  
  \param temp A string parameter parse stuff
*/

void check(string temp)
{
  size_t found = -1;
  
  //input and output
  string input = "IN";
  string output = "OUT";
  
  //gates
  string or_gate = "OR";
  string and_gate = "AND";
  string not_gate = "NOT";
  
  //wires
  string input_wire = "to";
  string wire = "WIRE";

   /* inputs outputs*/
   //input
   found=temp.find(input);
   if(found!=string::npos)
     {
       
       ginput temp_input;
       temp_input.set_name(temp[0]);
       in_array.push_back(temp_input);
     }
   //output
   found=temp.find(output);
   if(found!=string::npos)
     {

       goutput temp_output;
       temp_output.set_name(temp[0]);
       out_array.push_back(temp_output);
     }
    /* gates */
   //and
   found=temp.find(and_gate);
   if(found!=string::npos)
     {

       gate temp_gate(temp[0]);
       temp_gate.set_type(and_gate);
       gate_array.push_back(temp_gate);
     }
   //or
   found=temp.find(or_gate);
   if(found!=string::npos)
     {

       gate temp_gate(temp[0]);
       temp_gate.set_type(or_gate);
       gate_array.push_back(temp_gate);
     }
   //not
   found=temp.find(not_gate);
   if(found!=string::npos)
     {

       gate temp_gate(temp[0]);
       temp_gate.set_type(not_gate);
       gate_array.push_back(temp_gate);
     }
/*wires*/
   //from
   found=temp.find(wire);
   gwire t_gwire;
   if(found!=string::npos)
   { 

     t_gwire.set_name(temp[0]);
     t_gwire.set_from(temp[found+5]);


   }    
   //to
   found=temp.find(input_wire);
   if(found!=string::npos)
   {

     t_gwire.set_to(temp[found+3]);
     t_gwire.set_type(TYPE);
     gwire_array.push_back(t_gwire);   
   }



}

/**
  put_gate just basically insert inputs and outputs
  and flags
*/

void put_gate()
{
  for(int i = 0; i < (int)gwire_array.size(); ++i)
  {
    if(gwire_array[i].get_type() == "INPUT")
    {
      int gate_t = find_gate(gwire_array[i].get_to());
      int input_t = find_input(gwire_array[i].get_from());

      gate_array[gate_t].add_input(in_array[input_t]);
    }
    else if(gwire_array[i].get_type() == "INTERNAL")
    {
      int gate_t = find_gate(gwire_array[i].get_to());

      gate_array[gate_t].set_depend(gwire_array[i].get_from());
      
    }
    else if(gwire_array[i].get_type() == "OUTPUT")
    {
      int gate_t = find_gate(gwire_array[i].get_from());

      gate_array[gate_t].set_output(gwire_array[i].get_to());
      
    }
  }
}

/**
  *find_input is a helper function that return the index 
  *where the input rises

  \param t_input A char variable 
*/
int find_input(char t_input)
{
  int i;
  for(i=0; i < (int)in_array.size(); ++i)
  {
     if(in_array[i].get_name() == t_input)
	break;
  }
 return i;
} 

/**
  find_gate is a helper function that return the index 
  *where the gate rises

  \param t_gate A char variable represent the gate name
*/
int find_gate(char t_gate)
{
  int i;
  for(i=0; i < (int)gate_array.size(); ++i)
  {
     if(gate_array[i].get_name() == t_gate)
	break;
  }
 return i;
} 


/**
  find_gate_input is a helper function to set gate's values
  /param t_input Look for the input name
  /param t_val   Set the input value
*/
void find_gate_input(char t_input, bool t_val)
{

  for(int i=0; i < (int)gate_array.size(); ++i)
  {
   gate_array[i].set_input(t_input,t_val); 
  }

} 

/**
  *make_circuit() make the circuit and output the table

*/
void make_circuit()
{
  bool finish = false;
  int num_inputs = in_array.size();
  int table_size = (int)pow(2,num_inputs);
  int vector_size = table_size * num_inputs;


  int iter = table_size;

  for(int i=0; i < (int)vector_size; ++i)
   {
    logic_table.push_back(false);

   }  

   bool num = true;
   int i = 0;
   int j = 0 ;
  while (num)
  {
   if(j < num_inputs)
   {

     i = 0+j;
   }
   bool toggle = false;

   iter = iter/2;

 
  while(i < vector_size)
  {


      for(int k = 0; k < iter; ++k)
      {

       logic_table[i]=toggle;

       i+=num_inputs;
          
      }

   if(toggle == false)
     toggle = true;
   else if(toggle == true)
     toggle = false;


 
   
  }//end while vec
   if(iter == 1)
    num = false;
  ++j;
 } //end while


int m = 0;

  while(finish == false)
  {






 for( int w =0; w < (int)num_inputs; ++w) 
   {
     find_gate_input(in_array[w].get_name(),logic_table[m]);

     ++m;
   }


    aux();

   if(m > vector_size)
   finish = true; 

  } 



for(int i = 0; i < (int)in_array.size(); ++i)
{
  cout<<in_array[i].get_name()<<"    ";
}
cout<<"|";
for(int i=0; i< (int)out_array.size(); ++i)
{
  cout<<"    "<<out_array[i].get_name();
}
cout<<endl;
int max_slash = (((in_array.size()+out_array.size())*5)+1);

for(int i = 0; i < max_slash; ++i)
cout<<"-";
cout<<endl;
int print_endl = 0;
int iter_l = 0;
for(int i = 0; i < (int)vector_size; ++i)
 {
  cout<<logic_table[i]<< "    ";
  ++print_endl;
  
  if(print_endl == num_inputs)
  {
    cout<<"|    "<<logic_answer[iter_l];
    ++ iter_l;  
    cout<<endl;
    print_endl = 0;
  }

 }


}

/**
  *aux() function is the helper function for the make_circuit function
  *This function actually calculate the table!
*/
void aux()
{
bool done = false;
while(done == false)
{
 for(int i = 0; i < (int)gate_array.size(); ++i)
    {
      if(gate_array[i].get_dirty() == false 
         && gate_array[i].depend_status() == false)
      {
        gate_array[i].set_output_value(false,false);
      }
    }

 for(int i = 0; i < (int)gate_array.size(); ++i)
  {
    
   if(gate_array[i].get_dirty() == false 
         && gate_array[i].depend_status() == true 
         && gate_array[i].input_size() > 0 )
      {
        char internal_output_name = gate_array[i].get_depend();
        int t_index_gate = find_gate(internal_output_name);
        
        gate_array[i].set_output_value(gate_array[t_index_gate].output_value(), false);
      }

  }

 for(int i = 0; i < (int)gate_array.size(); ++i)
  {
    
   if(gate_array[i].get_dirty() == false 
         && gate_array[i].depend_status() == true)
      {
        char internal_output_name = gate_array[i].get_depend();
        int t_index_gate = find_gate(internal_output_name);

        char internal_output_name2 = gate_array[i].get_depend2();
        int t_index_gate2 = find_gate(internal_output_name2);
        
        gate_array[i].set_output_value(gate_array[t_index_gate].output_value(),
                                       gate_array[t_index_gate2].output_value());
      }//end if

  }//end for
bool check = true;
 for(int i = 0; i < (int)gate_array.size(); ++i)
 { 
  if(gate_array[i].get_dirty()==false)
   { check = false;}
 }
if(check == true)
done = true;

}//end while

for(int i = 0; i < (int)gate_array.size(); ++i)
{
  if(gate_array[i].check_last_gate()==true)
  {
    logic_answer.push_back(gate_array[i].output_value());
  }

}//end for

for(int i = 0; i < (int)gate_array.size(); ++i)
{
gate_array[i].set_dirtybit(false);
}



}
  private:
  string filename;///< This is will contain the file name
  vector<ginput> in_array;///< An array of inputs
  vector<goutput> out_array;///< An array of outputs
  vector<gate> gate_array;///< An array of gates
  vector<gwire> gwire_array;///< An array of wires
  vector<bool> logic_table;///< An array all possible inputs
  vector<bool> logic_answer;///< An array logical answers to all possible inputs
};

#endif /*GOUTPUT_H_*/


