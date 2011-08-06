#// Course:            CS 100

#// Lecture Section:   1
#// Lab time:					Friday 11-2 pm
#// Date completed:    
#// First Name:        Jay
#// Last Name:         Novilla
#// ID Number:         860802932
#// Email address:     jay-r.novilla@email.ucr.edu
#// Project:						1
#// =======================================================================**
CXX=/usr/bin/g++

CXXFLAGS= -g -W -Wall -pedantic -Weffc++

all:  gate.o wire.o NOT.o AND.o OR.o board.o main.cc 
	$(CXX)	$(CXXFLAGS) -o cs main.cc gate.o wire.o NOT.o AND.o OR.o board.o

board.o:	board.h gate.h wire.h NOT.h OR.h AND.h
	$(CXX)	$(CXXFLAGS)	-c board.cc

gate.o: gate.h wire.h 
	$(CXX)	$(CXXFLAGS)	-c gate.cc

NOT.o: NOT.h wire.h gate.h
	$(CXX)	$(CXXFLAGS)	-c NOT.cc		

AND.o: AND.h wire.h gate.h
	$(CXX)	$(CXXFLAGS)	-c AND.cc		

OR.o: OR.h wire.h gate.h
	$(CXX)	$(CXXFLAGS)	-c OR.cc		

wire.o:	wire.h
	$(CXX)	$(CXXFLAGS)	-c wire.cc
	
clean:
	/bin/rm -f cs *~ *.o


								
