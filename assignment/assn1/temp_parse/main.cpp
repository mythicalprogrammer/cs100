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
using namespace std;



string TYPE = "UNKNOWN";
vector<ginput> in_array;
vector<goutput> out_array;
vector<gate> gate_array;
vector<gwire> gwire_array;
vector<bool> logic_table;
vector<bool> logic_answer;
//list<gate> circuit; //baby you are the only one.
void check(string temp);
int find_gate(char t_gate);
void put_gate();
int find_input(char t_input);
void make_circuit();

void table_graph();
bool aux();
int main()
{

  string file_name;
  cout<<"name file: "<<endl;
  cin>>file_name;
  
  string temp = "";
  string text = "";
  int size_text = 0;
  ifstream infile; 
  char c = ' ';
 
  

  //OPEN TEXT FILE
  infile.open(file_name.c_str());


  while(infile)
  {
     
    if (infile.eof())
       break;

    infile.get(c);
    text += c;
    size_text++;

  }//end while

   //iter 
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
        }
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
       }
     }

     if(ignore == false)
     check(temp);// CEHCK;

    /*
    //DEBUGGER
    cout<<"i "<<i<<endl;
    //cout<<temp[i]<<endl;
    cout<< temp<<endl;

   */
  
   ++i;
   temp="";
   ignore = false;
 } //end while
 
cout<<"-------inputs ----------------"<<endl;
for(i = 0; i < in_array.size(); i++)
 {cout<<in_array[i].get_name();
 cout<<endl;
}

cout<<"-------outputs ----------------"<<endl;
for(i = 0; i < out_array.size(); i++)
 {cout<<out_array[i].get_name();
 cout<<endl;}

cout<<"-------gates----------------"<<endl;
for(i = 0; i < gate_array.size(); i++)
 {
  cout<<gate_array[i].get_name();
  cout<<endl;
 }

cout<<"-------WIRES----------------"<<endl;
for(i = 0; i < gwire_array.size(); i++)
 {

  //char a = ;
  cout << "NAME: " << gwire_array[i].get_name()<< " ";
  //a = ;
  cout << "FROM: " << gwire_array[i].get_from()<< " ";
  //a = ;
  cout << "TO: " << gwire_array[i].get_to()<< " ";
//
  cout << "TYPE: " << gwire_array[i].get_type();
  
/*
  char a = gwire_array[i].get_name();
  cout << "NAME: " << a;
  a = gwire_array[i].get_from();
  cout << "FROM: " << a;
  a = gwire_array[i].get_to();
  cout << "TO: " << a;*/ 
  cout<<endl; 
 }

put_gate();

cout<<"-------COMPLETE GATES----------------"<<endl;
for(i = 0; i < gate_array.size(); i++)
 {
   cout<<"GATE NAME: " << gate_array[i].get_name()<<endl;
   cout<<"INPUTS: " <<endl;
   gate_array[i].print_inputs();
   cout<<endl;
   cout<<"Depended: " <<endl;
   cout<<gate_array[i].depend_status()<<endl;
   cout<<"Internal: "<<endl;
   cout<<gate_array[i].get_depend()<<endl;;
   cout<<"Last Gate: "<<endl;
   cout<<gate_array[i].check_last_gate()<<endl; 
   
 }

make_circuit();

infile.close();
return 0;
}

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
       cout<<temp[0]<< " is an input."<<endl;
       ginput temp_input;
       temp_input.set_name(temp[0]);
       in_array.push_back(temp_input);
     }
   //output
   found=temp.find(output);
   if(found!=string::npos)
     {
       cout<<temp[0]<< " is an output."<<endl;
       goutput temp_output;
       temp_output.set_name(temp[0]);
       out_array.push_back(temp_output);
     }
/* gates */
   //and
   found=temp.find(and_gate);
   if(found!=string::npos)
     {
       cout<<temp[0]<< " is an and gate."<<endl;
       gate temp_gate(temp[0]);
       temp_gate.set_type(and_gate);
       gate_array.push_back(temp_gate);
     }
   //or
   found=temp.find(or_gate);
   if(found!=string::npos)
     {
       cout<<temp[0]<< " is an or gate."<<endl;
       gate temp_gate(temp[0]);
       temp_gate.set_type(or_gate);
       gate_array.push_back(temp_gate);
     }
   //not
   found=temp.find(not_gate);
   if(found!=string::npos)
     {
       cout<<temp[0]<< " is a not gate."<<endl;
       gate temp_gate(temp[0]);
       temp_gate.set_type(not_gate);
       gate_array.push_back(temp_gate);
     }
//wires
   //from
   found=temp.find(wire);
   gwire t_gwire;
   if(found!=string::npos)
   { 
     cout<<temp[0]<< " is a wire from "<< temp[found+5]<<" to ";
     t_gwire.set_name(temp[0]);
     t_gwire.set_from(temp[found+5]);


   }    
   //to
   found=temp.find(input_wire);
   if(found!=string::npos)
   {
     cout<<temp[found+3]<<endl;
     t_gwire.set_to(temp[found+3]);
     t_gwire.set_type(TYPE);
     gwire_array.push_back(t_gwire);   
   }



}

void put_gate()
{
  for(int i = 0; i < gwire_array.size(); ++i)
  {
    if(gwire_array[i].get_type() == "INPUT")
    {
      int gate_t = find_gate(gwire_array[i].get_to());
      int input_t = find_input(gwire_array[i].get_from());
      cout<<" input_name" << in_array[input_t].get_name()<<endl;
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

int find_input(char t_input)
{
  int i;
  for(i=0; i < in_array.size(); ++i)
  {
     if(in_array[i].get_name() == t_input)
	break;
  }
 return i;
} 

int find_gate(char t_gate)
{
  int i;
  for(i=0; i < gate_array.size(); ++i)
  {
     if(gate_array[i].get_name() == t_gate)
	break;
  }
 return i;
} 

void find_gate_input(char t_input, bool t_val)
{
  //int i;
  for(int i=0; i < gate_array.size(); ++i)
  {
   gate_array[i].set_input(t_input,t_val); 
  }

} 

void make_circuit()
{
  bool finish = false;
  int num_inputs = in_array.size();
  int table_size = (int)pow(2,num_inputs);
  int vector_size = table_size * num_inputs;

 //cout <<vector_size<<endl;
  int iter = table_size;

  for(int i=0; i < vector_size; ++i)
   {
    logic_table.push_back(false);
    //cout<<i<<endl;
   }  

   bool num = true;
   int i = 0;
   int j = 0 ;
  while (num)
  {
   if(j < num_inputs)
   {
     cout<<"j" <<j<<endl;
     i = 0+j;
   }
   bool toggle = false;

   iter = iter/2;
   cout<< "i: " << i<<endl;
   cout << "iter: " <<iter<<endl;
   cout<< "vector_size: "<<vector_size<<endl;
 
  while(i < vector_size)
  {


      for(int k = 0; k < iter; ++k)
      {
       cout<<"i: "<<i<<endl;
       cout<<"toggle: "<< toggle<<endl;
       logic_table[i]=toggle;
       cout<<"logic table " <<logic_table[i]<<endl;
       i+=num_inputs;
          
      }

   if(toggle == false)
     toggle = true;
   else if(toggle == true)
     toggle = false;

     //cout<<"i: "<<i<<endl;
 
   
  }//end while vec
   if(iter == 1)
    num = false;
  ++j;
 } //end while

int table_iter = 0;
int m = 0;

  while(finish == false)
  {


   //find values
     cout<<"m: "<<m<<endl;
     cout<<"numinput: "<<num_inputs<<endl;
/*
void find_gate_input(char t_input, bool t_val)
{
  //int i;
  for(int i=0; i < gate_array.size(); ++i)
  {
   gate_array[i].set_input(t_input,t_val); 
  }

} */


 for( int w =0; w < num_inputs; ++w) // every 3 
   {
     find_gate_input(in_array[w].get_name(),logic_table[m]);
     cout<<"w: "<<w<<endl;
     cout<<"m: "<<m<<endl;
     ++m;
   }
//cout<<"stop!"<<endl;

    aux();
     //cout<<"err?"<<endl;
   if(m > vector_size)
   finish = true; 

  } 

cout<<"a    b    c   |    d"<<endl;

int print_endl = 0;
int iter_l = 0;
for(int i = 0; i < vector_size; ++i)
 {
  cout<<logic_table[i]<< "    ";
  ++print_endl;
  
  if(print_endl == num_inputs)
  {
    cout<<logic_answer[iter_l];
    ++ iter_l;  
    cout<<endl;
    print_endl = 0;
  }

 }
/*
for(int i = 0; i < logic_answer.size(); ++i)
cout<< logic_answer[i]<< " ";*/
/*for(int i = 0; i <= table_size; ++i)
{
  for(int k = 0; k < num_inputs; ++k)
    cout<<logic_table[i]<<" ";
 cout<<endl;
}*/

}

bool aux()
{
bool done = false;
while(done == false)
{
 for(int i = 0; i < gate_array.size(); ++i)
    {
      if(gate_array[i].get_dirty() == false 
         && gate_array[i].depend_status() == false)
      {
        gate_array[i].set_output_value(false,false);
      }
    }

 for(int i = 0; i < gate_array.size(); ++i)
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

 for(int i = 0; i < gate_array.size(); ++i)
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
 for(int i = 0; i <gate_array.size(); ++i)
 { 
  if(gate_array[i].get_dirty()==false)
   { check== false;}
 }
if(check == true)
done = true;

}//end while

for(int i = 0; i < gate_array.size(); ++i)
{
  if(gate_array[i].check_last_gate()==true)
  {
    logic_answer.push_back(gate_array[i].output_value());
  }

}//end for

for(int i = 0; i < gate_array.size(); ++i)
{
gate_array[i].set_dirtybit(false);
}



}


