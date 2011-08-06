//Nguyen Do
//860734448
//ndo

#ifndef __PARSER_H
#define __PARSER_H

#include <iostream>
#include <string>
#include <fstream>
#include "connect.h"
#include "stringToUpperCase.h"

using namespace std;

class Parser{

 private:

  Connect connection;

  string inputFromFile;
  string upperCaseString;
  string name;
  int found;

 public:

  Parser(){
    inputFromFile = "";
    upperCaseString = "";
    name = "";
    found = 0;
  }

  void parseFile(string theFile){
    ifstream inputFile(theFile);

    /**
     * Check if file is opened
     * If not:
     * print error message
     * exit program
     */
    if(!(inputFile.is_open())){
      cout << "File can not be opened.";
      return -1;
    }

    /**
     * File is now open
     * Reading each line of the document
     * Parse each line
     * 
     */
    while(!(inputFile.eof())){
      getline(inputFile,inputFromFile); ///< Reads and store first line of file
      found = inputFromFile.find(":"); ///< Find position of ":" if there
      if(found!=-1){ ///< if ":" is present, found!=-1
	name = inputFromFile.substr(0,found); ///< Find the name
	/// Convert line to upper case
	StringToUpperCase lineFromFileUpperCase (inputFromFile);
	upperCaseString = lineFromFileUpperCase.returnUpperCase();

	///
	if(upperCaseString.find("WIRE")!=-1){
	  int positionWire = upperCaseString.find("WIRE");
	  int shiftForwardFrom = 5;
	  int start = positionWire + shiftForwardFrom;
	  int positionTo = upperCaseString.find("TO");
	  int shiftBackwardTo = 1;
	  int end = (positionTo - shiftBackwardTo) - start;
	  string from = inputFromFile.substr(start, end);

	  // Position of TO already found
	  int shiftForwardTo = 3;
	  start = positionTo + shiftForwardTo;
	  //int positionParenthesis = upperCaseString.find("(");
	  //int shiftBackwardParenthesis = 1;
	  string to = inputFromFile.substr(start, end);

	  connection.pushWire(from, to);
	}
	else if(upperCaseString.find("NOT")!=-1){
	  connection.pushGate(name, "NOT");
	}
	else if(upperCaseString.find("AND")!=-1){
	  connection.pushGate(name, "AND");
	}
	else if(upperCaseString.find("OR")!=-1){
	  connection.pushGate(name, "OR");
	}
	else if(upperCaseString.find("IN")!=-1){
	  connection.pushStoreValue(name, "IN");
	}
	else if(upperCaseString.find("OUT")!=-1){
	  connection.pushStoreValue(name, "OUT");
	}
      }
    }
    inputFile.close();
  }

  void createTable(){
    connection.createTable();
  }

};

#endif
