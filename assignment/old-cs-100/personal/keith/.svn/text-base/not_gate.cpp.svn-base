//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#include <string>
#include "wire.h"
#include "not_gate.h"

not_gate::not_gate()
{
	gateName = "";
}

not_gate::not_gate(string name)
{
	gateName = name;
}

not_gate::not_gate(wire* wire1, wire* wireOutput, string name)
{
	input0 = wire1;
	output = wireOutput;
	gateName = name;
}

wire* not_gate::get_input0()
{
	return input0;
}

wire* not_gate::get_output()
{
	return output;
}

string not_gate::get_name()
{
	return gateName;
}

void not_gate::set_name(string name)
{
	gateName = name;
}

void not_gate::set_connection(string connect_to, wire* wire1)
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
	else if (connect_type == "out")
	{
		output = wire1;
	}
	else
	{

	}
}

void not_gate::compute_output()
{
	if(input0->get_value() == 0)
	{
		output->set_value(1);
	}
	else
	{
		output->set_value(0);
	}
}
