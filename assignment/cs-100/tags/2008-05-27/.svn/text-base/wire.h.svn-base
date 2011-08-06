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

class Gate;
#ifndef _WIRE_H_
#define _WIRE_H_

#include <iostream>
#include "gate.h"
#include "object.h"
using namespace std;

class Wire
{
  friend class Gate;

  protected:
    string wireName;
    string wireType;//either external or internal
    bool wireCharge;
    Gate * intoGate;
    Gate * outofGate;
    bool disable;
  public:
    Wire();
    Wire(const Wire&);
    Wire(string,string);
    ~Wire();
    Wire& operator=(Wire);
    void set_charge(bool);
    void set_name(string);
    void set_type(string);
    void set_destinationGate(Gate*);
    void set_sourceGate(Gate*);
    void enableErrorCheck();
    void disableErrorCheck();
    //these gates are for finding the gates they go out of 
    //and into during the output phase
    bool get_charge();
    Gate * get_sourceGatepointer();
    string get_name();
    string get_type();
    
    //new stuff for cycle into self
    string get_destinationName();        
    string get_sourceName();
};

#endif
