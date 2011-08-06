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
//LIBRARIES-----------------------------------//
#include "termtextviewer.h"

using namespace std;


int main()
{

  //TEXT FILES
  string a = "./text_files/dec_independence.txt"; 
  string b = "./text_files/hamlet_act1_scene1.txt";
  string c = "./text_files/error.txt";
  
  //MAKING VIARIABLES FOR EACH TEXT FILE
   TermTextViewer dec_inde(a);
   TermTextViewer hamlet(b);
   TermTextViewer error(c);


  
   //TO VIEW IT
   hamlet.view();

   dec_inde.view();

   error.view();  





  return 0;

}
