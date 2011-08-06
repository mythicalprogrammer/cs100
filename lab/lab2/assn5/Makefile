#// Course:            CS 12 2005 Spring
#//
#// Lecture Section:   01
#// Lab Section:       22
#// Assignment #:      5
#//
#// First Name:        Quoc
#// Last Name:         Doan
#// Login id:          qdoan001
#// Student id:        860-75-9993
#//
#// Study group:       Sang Phan, Nam, Jessie, Scott, Moises, etc... ACM clubs
#                    
#
# =======================================================================
#LIBRARIES-----------------------------------//

CXX=g++
CXXFLAGS=-g -Wall -W -Werror -pedantic -ansi
OBJECTS=termtextviewer.o
#LIBS= -lX11 -lccc
#LIBDIRS = -L/usr/X11R6/lib -L/usr/local/lib -L/usr/csshare/lib

all:$(OBJECTS)
	$(CXX) $(CXXFLAGS) -o a.out main.cpp $(OBJECTS)

clean: 
	rm -rf *~ a.out *.o
