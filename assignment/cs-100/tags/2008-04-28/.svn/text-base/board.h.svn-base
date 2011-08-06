#ifndef _BOARD_H_
#define _BOARD_H_

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
#include <math.h>
class Board
{
private:
string inputFile;
vector <Wire*> inputWireVector;
vector <Wire*> outputWireVector;
vector <Gate*> gateVector;

public:
Board();
Board(string);
void Parse();
void setFile(string);
void Print();
void Print(string);
void Binary(int number,vector<int> &  intVector);
};
#endif
