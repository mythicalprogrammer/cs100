CXX= g++

CXXFLAGS= -g -Wall -W -Werror -pedantic

OBJECTS= wire.o and_gate.o or_gate.o not_gate.o input_output.o board.o

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o cs main.cpp $(OBJECTS)

wire.o: wire.h wire.cpp
	$(CXX) $(CXXFLAGS) -o wire.o -c wire.cpp

and_gate.o: and_gate.h and_gate.cpp wire.h
	$(CXX) $(CXXFLAGS) -o and_gate.o -c and_gate.cpp

or_gate.o: or_gate.h or_gate.cpp wire.h
	$(CXX) $(CXXFLAGS) -o or_gate.o -c or_gate.cpp

not_gate.o: not_gate.h not_gate.cpp wire.h
	$(CXX) $(CXXFLAGS) -o not_gate.o -c not_gate.cpp

input_output.o: input_output.h input_output.cpp wire.h
	$(CXX) $(CXXFLAGS) -o input_output.o -c input_output.cpp

board.o: board.h board.cpp wire.h and_gate.h or_gate.h not_gate.h input_output.h
	$(CXX) $(CXXFLAGS) -o board.o -c board.cpp



clean:
	-rm -rf *~ *.o cs
