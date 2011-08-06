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
CXX=g++

CXXFLAGS= -g -W -Wall -Werror -pedantic -ansi

all:  gate.o wire.o main.cc
	$(CXX)	$(CXXFLAGS) -o cs main.cc gate.o wire.o

gate.o: gate.h
	$(CXX)	$(CXXFLAGS)	-c gate.cc
	
wire.o:	wire.h
	$(CXX)	$(CXXFLAGS)	-c wire.cc
	
clean:
	rm -f cs *~ *.o


								
