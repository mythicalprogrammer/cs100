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

using namespace std;

// Object class is the base class for all
// objects in the system. All classes inheriting from this class need 
// to define a method IsValid. This method should perform a
// consistency check on the state of the object. Note that 
// this method needs to be defined only when a debug build is made
class Object
{
  public:

    virtual ~Object(){}

    #ifdef _DEBUG
      bool IsValid() const = 0;
    #endif
    
};

#ifdef _DEBUG

// The debug mode also defines the following macros. Failure of any of these macros leads to
// program termination. The user is notified of the error condition with the right file name
// and line number. The actual failing operation is also printed using the stringizing operator #

#define ASSERT(bool_expression) if (!(bool_expression)) abort_program(__FILE__, __LINE__, #bool_expression)
#define IS_VALID(obj) ASSERT((obj) != NULL && (obj)->IsValid())
#define REQUIRE(bool_expression) ASSERT(bool_expression)
#define ENSURE(bool_expression) ASSERT(bool_expression)

#else

// When built in release mode, the _DEBUG flag would not be defined, thus there will be no overhead
// in the final release from these checks.

#define ASSERT(ignore) ((void) 0)
#define IS_VALID(ignore) ((void) 0) 
#define REQUIRE(ignore) ((void) 0)
#define ENSURE(ignore) ((void) 0)

#endif

#endif
