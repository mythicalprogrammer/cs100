// Course:            CS 12 2005 Spring
//
// Lecture Section:   01
// Lab Section:       22
// Assignment #:      5
//
// First Name:        Quoc
// Last Name:         Doan
// Login id:          qdoan001
// Student id:        860-75-9993
//
// Study group:       Sang Phan, Nam, Jessie, Scott, Moises, etc... ACM clubs
//                    
//
// =======================================================================
//-----------------------------------//
// Course:              CS 12
// Assignment #:        4-5 Solutions
// ========================================================================
//! \file termtextviewer.h
//! \brief Delaration of the TermTextViewer class.

#ifndef __TERMTEXTVIEWER_H__
#define __TERMTEXTVIEWER_H__

#include <string>


using namespace std;

//! \class TermTextViewer
//! \brief A facility for viewing the contents of a file.
class TermTextViewer
{
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                Constructors and Destructors                ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 public:
  //! \brief Default constructor for the TermTextViewer Class.
  TermTextViewer();

  //! \brief Constructor for the TermTextViewer Class.
  //! \param name_of_file The name of the file to view.
  TermTextViewer( const std::string & name_of_file );

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Accessors                         ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                          Mutators                          ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  //! \brief Set the name of the file to view.
  //! \param name_of_file The name of the file to view.
  //! \return Void.
  void setFile( const std::string & name_of_file );

  //! \brief View the contents of the file.
  //! \return Void.
  void view();

  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~                 Private Members and Data                   ~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 private:
  //! \brief Read in the contents of the file.
  //! \return Void.
  void readTextFromFile();
  
  //! \brief Display the next page in the graphic window.
  //! \return Void.
  void showNextPage();
  
  //! \brief Check if all of the text from the file has been displayed.
  //! \return Whether the entire contents of the file has been displayed.
  bool allTextDisplayed();

  std::string file_name;	//!< The name of the file.
  std::string text;		//!< The text from the file.
  //int cur_text_index2;	//!< The current index into the text.

  int cur_text_index;

  bool next_page;

};

#endif // __TERMTEXTVIEWER_H__
