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
#include "object.h"

class Board
{
  private:
    string inputFile;
    vector <Wire*> inputWireVector;
    vector <Wire*> outputWireVector;
    vector <Gate*> gateVector;
    bool disable;

  public:
    Board();
    Board(string);
    virtual ~Board();
    void Parse();
    void setFile(string);
    void Print();
    void Print(string);
    void Binary(int number,vector<int> &  intVector);
    void enableErrorCheck();
    void disableErrorCheck();
    void disableAllErrorCheck();
    void enableAllErrorCheck();
};

#endif
