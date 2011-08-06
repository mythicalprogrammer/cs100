#Nguyen Do
#860734448
#ndo

CXX = g++

OBJECTS = stringToUpperCase.o gates.o

HEADERS = connect.h parser.h storeValues.h wires.h

HEADERSGATES = gates.h storeValues.h stringToUpperCase.h

CPPGATES = gates.cpp stringToUpperCase.cpp

all: program
	rm -rf *.o

program: $(OBJECTS) $(HEADERS)
	$(CXX) -o cs main.cpp $(OBJECTS) $(HEADERS)

stringToUpperCase.o: stringToUpperCase.h stringToUpperCase.cpp
	$(CXX) -o stringToUpperCase.o -c stringToUpperCase.cpp

gates.o: $(HEADERSGATES) $(CPPGATES)
	$(CXX) -o gates.o -c gates.cpp

clean:
	rm -rf *~ *.o cs
