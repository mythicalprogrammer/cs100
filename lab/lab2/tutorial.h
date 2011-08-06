/**
 * \file tutorial.h
 * \author Chris Olsen
 * \date 2-26-04
 */
#ifndef __TUTORIAL__
#define __TUTORIAL__



/**
 * An example class for the Doxygen tutorial
 */
class Tutorial
{
public:
  /// The Constructor
  Tutorial();

  /** The Destructor */
  virtual ~Tutorial();

  /**
     Takes three inputs and does something

     \param a A float paramater
     \param b An int paramater
     \param c A char paramater
     \return Returns an integer
  */
  int Method1(float a, int b, char c);

  int var;  ///< This was commented after declaration
};
 
#endif
