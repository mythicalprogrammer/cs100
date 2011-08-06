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

CXXFLAGS= -g -W -Wall -pedantic -Weffc++ -O0 -fprofile-arcs -ftest-coverage

all:  gate.o wire.o NOT.o AND.o OR.o board.o main.cc object.h
	$(CXX)	$(CXXFLAGS) -o cs main.cc gate.o wire.o NOT.o AND.o OR.o board.o ; /bin/rm -rf *.o

board.o: board.h gate.h wire.h NOT.h OR.h AND.h
	$(CXX)	$(CXXFLAGS)	-c board.cc

gate.o: gate.h gate.cc wire.h
	$(CXX)	$(CXXFLAGS)	-c gate.cc

NOT.o: NOT.h NOT.cc wire.h gate.h 
	$(CXX)	$(CXXFLAGS)	-c NOT.cc		

AND.o: AND.h AND.cc wire.h gate.h
	$(CXX)	$(CXXFLAGS)	-c AND.cc		

OR.o: OR.h OR.cc wire.h gate.h
	$(CXX)	$(CXXFLAGS)	-c OR.cc		

wire.o:	wire.h wire.cc
	$(CXX)	$(CXXFLAGS)	-c wire.cc

clean:
	/bin/rm -f cs *~ *.o *.gcda *.gcno

