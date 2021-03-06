// Course:            CS 100
// Group:             Deviant Programmers
// Lecture Section:   1
// Lab time:					Friday 11-2 pm
// Date completed:    4/28/08
// Names:             Jay Novilla
//                    Quoc Doan
//                    Keith Ailshie
//                    Nguyen Do
// ID Number:         Jay Novilla:860802932
//                    Quoc Doan:860759993
//                    Keith Ailshie:860816418
//                    Nguyen Do:860734448
// Login:             jnovilla
//                    qdoan
//                    ndo
//                    kailshie
// Project:						2
// =======================================================================**


#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <ostream>
#include "gate.h"
#include "wire.h"
#include "AND.h"
#include "OR.h"
#include "NOT.h"
#include "board.h"
#include <math.h>
#include <iostream>
using namespace std;

Board::Board()
{
inputFile="";
}
Board::Board(string inputString)
{
inputFile=inputString;
}

void Board::setFile(string inputString){
inputFile=inputString;
}


void Board::Parse(){


ifstream inputStream;
inputStream.open(inputFile.c_str());

if(!inputStream)
{
  cout << "incorrect input/output file"
       << endl;
  exit(0);
}

string inputString,
       inputString_2, 
       inputString_3,
       inputString_4,
       junkEater,
       tester;
int countWire=0;
int countGate=0;
int countGate_2=0;
int junkNumber=0;





  while(!inputStream.eof())
	{
	
	  inputStream >> inputString;
	  //removes comments
	  if(inputString=="#")
		{
		  getline(inputStream,inputString);
		 
		}
		
		else
		{
		  if(inputString.substr(inputString.size()-1,1)==":")
			{
					inputStream >> inputString_2;
					   //in the case of input and output wires
					   if(strcasecmp(inputString_2.c_str(),"IN")==0 or 
					      strcasecmp(inputString_2.c_str(),"OUT")==0)
					   {
					     //for input wires it creates one
					     if(strcasecmp(inputString_2.c_str(),"IN")==0)
					     {
					   	   Wire * incomingWire=new Wire(inputString.substr(0,1),"external");	
					   	   inputWireVector.push_back(incomingWire);
					     }
					     else// for output wires it creates one
					     {
					       Wire * incomingWire=new Wire(inputString.substr(0,1),"external");	
					       outputWireVector.push_back(incomingWire);
					     }
					   }
					   //for the gates
					   else if(strcasecmp(inputString_2.c_str(),"AND")==0 or 
					      strcasecmp(inputString_2.c_str(),"NOT")==0 or 
					      strcasecmp(inputString_2.c_str(),"OR")==0)
					   {  //for the AND gate
					     if(strcasecmp(inputString_2.c_str(),"AND")==0)
					     {
					   	   AND * incomingGate=new AND(inputString.substr(0,1));	
					   	   gateVector.push_back(incomingGate);
					     }//for the OR gate
					     else if(strcasecmp(inputString_2.c_str(),"OR")==0)
					     {
					   	   OR * incomingGate=new OR(inputString.substr(0,1));	
					   	   gateVector.push_back(incomingGate);
					     }
					    else//for the NOT gate
					     {
					   	   NOT * incomingGate=new NOT(inputString.substr(0,1));	
					   	   gateVector.push_back(incomingGate);
					     }
					   
					   }
					   //the word wire indicates its binding things together
					   else if(strcasecmp(inputString_2.c_str(),"WIRE")==0)// the second word is Wire
					   {
					     inputStream >> inputString_3; 
					     
					     if(inputString_3.size()==1)// means its an input wire
					     { countWire=0;
					       countGate=0;
					       tester=inputWireVector[0]->get_name();
					       
					       //finds the wire it needs
					       while(strcasecmp(tester.c_str(),inputString_3.c_str())!=0)
					       {
					         countWire++;
					         tester=inputWireVector[countWire]->get_name();
					       }
					       inputStream >> junkEater >> inputString_4;
					       countGate=0;
					       tester=gateVector[0]->get_gateName();
					       
					       //finds the gate its looking for
					       while(strcasecmp(tester.c_str(),inputString_4.substr(0,1).c_str())!=0)
					       {
					         countGate++;
					         tester=gateVector[countGate]->get_gateName();
					       }
					       junkNumber=atoi(inputString_4.substr(inputString_4.size()-2,1).c_str());
					       
					       inputWireVector[countWire]->set_destinationGate(gateVector[countGate]);
					       //binds the wire to the first input of the gate
					       if(junkNumber==0)
					       {
					         gateVector[countGate]->setWireZero(inputWireVector[countWire]);
					        
					       }
					       
					       else// binds the wire to the second input of the gate
					       {
					         gateVector[countGate]->setWireOne(inputWireVector[countWire]);
					       }
					       
					     }
				       //indicates its an output of somekind- either internal or external
					     else if(inputString_3.substr(inputString_3.size()-1,1)==")")
					     {
					       countWire=0;
					       countGate=0;
					       countGate_2=0;
					       inputStream >> junkEater >> inputString_4;
					       
					       //for internal wires only
					       if(inputString_4.substr(inputString_4.size()-1,1)==")")
					       // means its an input of a gate
					       {//internal wires
					           tester=gateVector[0]->get_gateName();
					       	   while(strcasecmp(tester.c_str(),inputString_3.substr(0,1).c_str())!=0)
					       	  
					           {
					           countGate++;
					           tester=gateVector[countGate]->get_gateName();
					           }
					           tester=gateVector[0]->get_gateName();
					       	   while(strcasecmp(tester.c_str(),inputString_4.substr(0,1).c_str())!=0)
					       	
					           {
					             countGate_2++; 
					             tester=gateVector[countGate_2]->get_gateName();
					           }
					         	
					            junkNumber=atoi(inputString_4.substr(inputString_4.size()-2,1).c_str());
					           Wire * internal=new Wire("internalJunk","internal");
					           inputWireVector.push_back(internal);
					           Gate * gateJunk=NULL;
					           gateVector[countGate]->setWireOut(internal);
					           gateJunk=gateVector[countGate_2];
					           internal->set_destinationGate(gateJunk);
					           internal->set_sourceGate(gateVector[countGate]);
					            if(junkNumber==0)
					           {
					             gateVector[countGate_2]->setWireZero(gateVector[countGate]->get_OutputWire());
					          
					         
					           }
                     else
                     {
					             gateVector[countGate_2]->setWireOne(gateVector[countGate]->get_OutputWire());
					           }
					       }
					     
					     else//for solely output wires of gates
					     {   
					           tester=outputWireVector[0]->get_name();
					           //finds the wire
					           while(strcasecmp(tester.c_str(),inputString_4.c_str())!=0)
					           {
					             countWire++;
					             tester=outputWireVector[countWire]->get_name();
					           }
					           tester=gateVector[0]->get_gateName();
					           //finds the gate
					           while(strcasecmp(tester.c_str(),inputString_3.substr(0,1).c_str())!=0)
					           {
					              countGate++;
					              tester=gateVector[countGate]->get_gateName();
					           }
					          gateVector[countGate]->setWireOut(outputWireVector[countWire]);
					          outputWireVector[countWire]->set_sourceGate(gateVector[countGate]);
					      }
					     }
					     }
					   }
					   else
					   {
					   cout << "ERROR IN THE INPUT." << endl;
					   return;
					   }
				
	  }
	
	}


  inputStream.close();



}





void Board::Print(){
if(inputWireVector.size()==0 or gateVector.size()==0)
{
cout << "Board is empty." << endl;
return;
}

	 unsigned int count=0;
	
	
  int numberExternalWires=0;
	count=0;
	//determines how many times to output the input names based on the size of the vector
	while(count<inputWireVector.size())
	{
	  if(inputWireVector[count]->get_type()=="external")
	  {
	  numberExternalWires++;
	  }
	  count++;
	}
	//determines the number of rows using powers 2^n
	double numberJunk=pow(2,numberExternalWires);
	int numberRows=int(numberJunk);
	vector< vector<double> > inputMatrix(numberRows,vector<double>(numberExternalWires));	
	
	count=0;
  //populates the matrix with 0's
	for(int i=0;i<numberRows;i++)
	{
	  for(int j=0; j<numberExternalWires;j++)
	  {
	    inputMatrix[i][j]=0;
	    
	  }
	  
	}
	
	
	
	
	
	
	//displays the input names
	for(int a=0; a<numberExternalWires;a++ )
	{
    if(inputWireVector[a]->get_type()!="internal")
    {
      cout << inputWireVector[a]->get_name() << "    ";
    }
	}
	cout << "|    ";
	//displays the output names
	for(unsigned int b=0; b<outputWireVector.size();b++ )
	{
    
      cout << outputWireVector[b]->get_name() << "    ";
    
	}
		
	cout << endl;
	//the filling of the matrix
	for(int i=0;i<numberRows;i++)
	{
	  vector<int> inputNumbers;
	  Binary(i,inputNumbers);
	  
	  if(inputNumbers.size()>2) 
	  {
	    
	    for(int j=0; j<numberExternalWires;j++)
	    {
   
	   
	      inputMatrix[i][j]=inputNumbers[j];
	      inputWireVector[j]->set_charge(inputMatrix[i][j]);
	     
	    
	    }
	  }
	  
	  //else
	//  {
	    int dumb=inputNumbers.size();
	    for(int j=numberExternalWires-1; j>=0;j--)
	    {
     
	     if(dumb>0)
	     {
	        inputMatrix[i][j]=inputNumbers[dumb-1];
	        
	        //cout << inputMatrix[i][j] << "    ";
	        dumb--;
	     } 
	     inputWireVector[j]->set_charge(inputMatrix[i][j]);
	      // j++;
	   
	    
	    }
	    
	  
	  //}
	  //outputs the left side of the truth table
	    for(int l=0; l<numberExternalWires;l++)
	    {
   
	   
			  //inputWireVector[l]->set_charge(inputMatrix[i][l]);
	      cout << inputMatrix[i][l] << "    ";
	    
	    
	    }
	    cout << "|    ";
	    //outputs the output of the circuit simulator for each row
	    for(unsigned int k=0; k<outputWireVector.size();k++)
	  {
	    Gate * outputGate=outputWireVector[k]->get_sourceGatepointer();
	    outputGate->gateOutput();
	    if(outputWireVector[k]->get_charge())
	    {
	      cout << "1";
	    }
	    else 
	    {
	    cout << "0";
	    }
	   
	  }
	  
	  
	    
	  cout << endl;
	}





}



/////////////
// this is the new print
/////////////





void Board::Print(string outputFile){
if(inputWireVector.size()==0 or gateVector.size()==0)
{
cout << "Board is empty." << endl;
return;
}

   ofstream outputStream;
   outputStream.open(outputFile.c_str(),ios::app);
   if(!outputStream)
   {
   cout << "incorrect output file"
        << endl;
   return;
   
   }

	 unsigned int count=0;
	
	
  int numberExternalWires=0;
	count=0;
	//determines how many times to output the input names based on the size of the vector
	while(count<inputWireVector.size())
	{
	  if(inputWireVector[count]->get_type()=="external")
	  {
	  numberExternalWires++;
	  }
	  count++;
	}
	//determines the number of rows using powers 2^n
	double numberJunk=pow(2,numberExternalWires);
	int numberRows=int(numberJunk);
	vector< vector<double> > inputMatrix(numberRows,vector<double>(numberExternalWires));	
	
	count=0;
  //populates the matrix with 0's
	for(int i=0;i<numberRows;i++)
	{
	  for(int j=0; j<numberExternalWires;j++)
	  {
	    inputMatrix[i][j]=0;
	    
	  }
	  
	}
	
	
	
	
	
	
	//displays the input names
	for(int a=0; a<numberExternalWires;a++ )
	{
    if(inputWireVector[a]->get_type()!="internal")
    {
      outputStream << inputWireVector[a]->get_name() << "    ";
    }
	}
	outputStream << "|    ";
	//displays the output names
	for(unsigned int b=0; b<outputWireVector.size();b++ )
	{
    
      outputStream << outputWireVector[b]->get_name() << "    ";
    
	}
		
	outputStream << endl;
	//the filling of the matrix
	for(int i=0;i<numberRows;i++)
	{
	  vector<int> inputNumbers;
	  Binary(i,inputNumbers);
	  
	  if(inputNumbers.size()>2) 
	  {
	    
	    for(int j=0; j<numberExternalWires;j++)
	    {
   
	   
	      inputMatrix[i][j]=inputNumbers[j];
	      inputWireVector[j]->set_charge(inputMatrix[i][j]);
	     
	    
	    }
	  }
	  
	  //else
	//  {
	    int dumb=inputNumbers.size();
	    for(int j=numberExternalWires-1; j>=0;j--)
	    {
     
	     if(dumb>0)
	     {
	        inputMatrix[i][j]=inputNumbers[dumb-1];
	        
	        //cout << inputMatrix[i][j] << "    ";
	        dumb--;
	     } 
	     inputWireVector[j]->set_charge(inputMatrix[i][j]);
	      // j++;
	   
	    
	    }
	    
	  
	  //}
	  //outputs the left side of the truth table
	    for(int l=0; l<numberExternalWires;l++)
	    {
   
	   
			  //inputWireVector[l]->set_charge(inputMatrix[i][l]);
	      outputStream << inputMatrix[i][l] << "    ";
	    
	    
	    }
	    outputStream << "|    ";
	    //outputs the output of the circuit simulator for each row
	    for(unsigned int k=0; k<outputWireVector.size();k++)
	  {
	    Gate * outputGate=outputWireVector[k]->get_sourceGatepointer();
	    outputGate->gateOutput();
	    if(outputWireVector[k]->get_charge())
	    {
	      outputStream << "1";
	    }
	    else 
	    {
	    outputStream << "0";
	    }
	   
	  }
	  
	  
	    
	  outputStream << endl;
	}





}






void Board::Binary(int number,vector<int> & intVector)
{
	int remainder;

	if(number <= 1) 
	{
	  intVector.push_back(number);
		
		return;
	}

	remainder = number%2;
	Binary(number >> 1,intVector);
	intVector.push_back(remainder);    
	

}

