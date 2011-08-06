//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#include <string>
#include "board.h"

using namespace std;

int main()
{
	board circuitBoard;
	string fileName;

	fileName = "input2.txt";

	circuitBoard.parse_file(fileName);

	circuitBoard.print_results();

	return 0;
}
