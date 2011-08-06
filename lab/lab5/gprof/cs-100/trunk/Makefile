#// Course:            CS 100
#// Group:             Deviant Programmers
#// Lecture Section:   1
#// Lab time:					Friday 11-2 pm
#// Date completed:    4/28/08
#// Names:             Jay Novilla
#//                    Quoc Doan
#//                    Keith Ailshie
#//                    Nguyen Do
#// ID Number:         Jay Novilla:860802932
#//                    Quoc Doan:860759993
#//                    Keith Ailshie:860816418
#//                    Nguyen Do:860734448
#// Login:             jnovilla
#//                    qdoan
#//                    ndo
#//                    kailshie
#// Project:						2
#// =======================================================================**

CXX=/usr/bin/g++

CXXFLAGS= -g -W -Wall -pedantic -Weffc++ -pg

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


								
