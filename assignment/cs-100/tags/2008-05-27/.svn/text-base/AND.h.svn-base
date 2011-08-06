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


class Wire;
#ifndef _AND_H_
#define _AND_H_
#include <iostream>
#include "gate.h"
#include "wire.h"
#include "object.h"

using namespace std;

class AND:public Gate
{
friend class Wire;
public:
AND();
AND(string);
void gateOutput();//will have wires as left and right and if its an output wire it will just call gateOutput() again
void gateOutput(Wire*);
};
#endif
