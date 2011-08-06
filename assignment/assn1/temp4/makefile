CXX=g++

CXXFLAGS= -g -W -Wall -Werror -pedantic -ansi 

all: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(LIBDIRS) -o cs main.cpp $(OBJECTS) $(LIBS)

clean:
	rm -rf *~ a.out *.o
