// Course:            CS 100

// Lecture Section:   1
// Lab time:					Friday 11-2 pm
// Date completed:    
// First Name:        Jay
// Last Name:         Novilla
// ID Number:         860802932
// Email address:     jay-r.novilla@email.ucr.edu
// Project:						1
// =======================================================================**

#include <iostream>
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
#include <cstdlib>
#include <sys/stat.h>
#include <stdio.h>

using namespace std;

bool FileExists(string strFilename); //http://www.techbytes.ca/techbyte103.html
int main(int argc, char* argv[])
{
  /*
  if(argc>2)
  {
    return 0;
  }
  */

  vector <string> inputVector;
  string outputFile="";

  if(argc==1)
  { 
    cout << "incorrect use of parameters"
         << endl;
    cout << "Gate Logic -- help option"<<endl;
    cout << "-h --help the help page"<<endl;
    cout << "This command gives helpful tips"<<endl;
    cout << "-v --version "<<endl;
    cout << "return the version values"<<endl;
    cout << "-i --input "<<endl;
    cout << "takes input file name"<<endl;
    cout << "-o --output"<<endl;
    cout << "Output stuff"<<endl;
    return 0;
  }

int count = 1;

while (count < argc)
{
  if (strcasecmp(argv[count],"-h")==0 || 
      strcasecmp(argv[count],"--help")==0)
  {
    cout << "Gate Logic -- help option"<<endl;
    cout << "-h --help the help page"<<endl;
    cout << "This command gives helpful tips"<<endl;
    cout << "-v --version "<<endl;
    cout << "return the version values"<<endl;
    cout << "-i --input "<<endl;
    cout << "takes input file name"<<endl;
    cout << "-o --output"<<endl;
    cout << "Output stuff"<<endl;
    return 0;
  }
  else if(strcasecmp(argv[count],"-v")==0 || 
          strcasecmp(argv[count],"--version")==0 )
  {
    //cout the help or readme file
    cout << "Version:"
         << "1.0"
         << endl;
     return 0;
  }

  count++;
}

count = 1;

while (count < argc)
{
  if (strcasecmp(argv[count],"-i")==0 || 
      strcasecmp(argv[count],"--input")==0)
  {
    ifstream inputFile;
    inputFile.open(argv[count+1]);
   
    if (inputFile.is_open())
    {
      inputVector.push_back(argv[count+1]);
      inputFile.close();
    }
  }
 
  count++;
}

count = 1;
while (count<argc)
{
  if (strcasecmp(argv[count],"-o")==0 || 
      strcasecmp(argv[count],"--output")==0 )
  {
    outputFile=argv[count+1];
    break;
  }

  count++;
} 
  
bool check = FileExists(outputFile);

if (check == true)
{
  string newOutput="~";
  newOutput +=outputFile;
  rename( outputFile.c_str(),newOutput.c_str());
}

//command line arguements
unsigned int count2 = 0;

if (strcasecmp(outputFile.c_str(),"") != 0)
{
  while (count2 < inputVector.size())
  {
    Board * bread=new Board();
    bread->setFile(inputVector[count2]);
    bread->Parse();
    bread->Print(outputFile);
    count++;
  }

  return 0;
} 

if (inputVector.size() > 0)
 {
   count2 = 0;
   
   while (count2 < inputVector.size())
   {
     Board * bread=new Board();
     bread->setFile(inputVector[count2]);
     bread->Parse();
     bread->Print();
     count++;
   }

   return 0;
 }
  
 Board bread= Board();
 bread.setFile(argv[1]);
 bread.Parse();
 bread.Print();
 return 0;
}



bool FileExists(string strFilename) {
  struct stat stFileInfo;
  bool blnReturn;
  int intStat;

  // Attempt to get the file attributes
  intStat = stat(strFilename.c_str(),&stFileInfo);
  if(intStat == 0) {
    // We were able to get the file attributes
    // so the file obviously exists.
    blnReturn = true;
  } else {
    // We were not able to get the file attributes.
    // This may mean that we don't have permission to
    // access the folder which contains this file. If you
    // need to do that level of checking, lookup the
    // return values of stat which will give you
    // more details on why stat failed.
    blnReturn = false;
  }
  
  return(blnReturn);
}
