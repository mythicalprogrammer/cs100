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
#ifndef _OBJECT_H_
#define _OBJECT_H_

#include<iostream>

using namespace std;

// Object class is the base class for all
// objects in the system. All classes inheriting from this class need 
// to define a method IsValid. This method should perform a
// consistency check on the state of the object. Note that 
// this method needs to be defined only when a debug build is made
//class Object
//{
  //public:
    //virtual ~Object(){}
//};

// The debug mode also defines the following macros. Failure of any of these macros leads to
// program termination. The user is notified of the error condition with the right file name
// and line number. The actual failing operation is also printed using the stringizing operator #

#define ASSERT(bool_expression) if (!(bool_expression)){ cout << "\nERROR: " << #bool_expression << endl; exit(0);}
#define REQUIRE(bool_expression) ASSERT(bool_expression)
#define ENSURE(bool_expression) ASSERT(bool_expression)

#endif
