//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#include "or_gate.h"
#include "wire.h"
#include <string>

using namespace std;

or_gate::or_gate()
{
	gateName = "";
}

or_gate::or_gate(string name)
{
	gateName = name;
}


or_gate::or_gate(wire* wire1, wire* wire2, wire* wireOutput, string name)
{
	input0 = wire1;
	input1 = wire2;
	output = wireOutput;

	gateName = name;
}

wire* or_gate::get_input0()
{
	return input0;
}

wire* or_gate::get_input1()
{
	return input1;
}

wire* or_gate::get_output()
{
	return output;
}

string or_gate::get_name()
{
	return gateName;
}

void or_gate::set_name(string name)
{
	gateName = name;
}

void or_gate::set_connection(string connect_to, wire* wire1)
{
	//find out what is inside the parenthesis so that the program
	//knows where to connect the wire to
	int str_pos1 = connect_to.find("(");
	int str_pos2 = connect_to.find(")");

	string connect_type = connect_to.substr((str_pos1 + 1), (str_pos2 - (str_pos1 + 1)));

	if (connect_type == "0")
	{
		input0 = wire1;
	}
	else if (connect_type == "1")
	{
		input1 = wire1;
	}
	else if (connect_type == "out")
	{
		output = wire1;
	}
	else
	{

	}
}

void or_gate::compute_output()
{
	if(input0->get_value() == 0 && input1->get_value() == 0)
	{
		output->set_value(0);
	}
	else
	{
		output->set_value(1);
	}
}
