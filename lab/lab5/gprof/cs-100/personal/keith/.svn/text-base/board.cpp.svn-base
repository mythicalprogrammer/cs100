//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "board.h"
#include "input_output.h"
#include "and_gate.h"
#include "or_gate.h"
#include "not_gate.h"
#include "wire.h"

using namespace std;

board::board()
{

}

void board::parse_file(string fileName)
{
	string line_input;
	string name;
	string type;
	int str_pos;

	ifstream inputFile(fileName.c_str());

	//If the file was opened successfully, then begin to parse the file.
	if (inputFile.is_open())
	{
		//Run through the file until the end of the file has been reached.
		while (!inputFile.eof())
		{
			getline(inputFile, line_input);

			//If the line taken from the input file is not a comment line
			//or a blank line begin parsing it.
			if (line_input[0] != '#' && line_input != "")
			{
				str_pos = line_input.find(":");
				name = line_input.substr(0,str_pos);
				//The (+ 2) in the below line is so the "type" string does not
				//include the ":" or the " " that is in the input file.
				type = line_input.substr(str_pos + 2);	

				//cout << "Name: " << name << " | Type : " << type << endl;

				//Find out what type of object is being added
				if(type == "IN")
				{
					add_input(name);
					//cout << "Added an input named : " << name << endl;
				}
				else if (type == "OUT")
				{
					add_output(name);
					//cout << "Added an output named : " << name << endl;
				}
				else if (type == "AND")
				{
					add_and_gate(name);
					//cout << "Added an and gate named : " << name << endl;
				}
				else if (type == "OR")
				{
					add_or_gate(name);
					//cout << "Added an or gate named : " << name << endl;
				}
				//Error check to make sure the string is long enough to 
				//do a substring on
				else if(type.size() > 4)
				{
					if (type.substr(0,4) == "WIRE")
					{
						string source;
						string destination;
						int str_pos;

						//Remove the "WIRE" from the parsing string
						str_pos = type.find(" ");
						type = type.substr(str_pos + 1);

						//Extract the source value and remove it from the
						//parsing string
						str_pos = type.find(" ");
						source = type.substr(0, str_pos);
						type = type.substr(str_pos + 1);

						//Extract te destination value
						str_pos = type.find(" ");
						destination = type.substr(str_pos + 1);

						add_wire(source, destination, name);
						//cout << "Added a wire named : " << name << endl;		
					}
				}
				else
				{
				}
			}			
		}
	}
	else
	{
		cout << "File (" << fileName << ")failed to open." << endl;
	}
}

void board::add_input(string name)
{
	input_output input(name);

	inputs.push_back(input);
}

void board::add_output(string name)
{
	input_output output(name);

	outputs.push_back(output);
}

void board::add_and_gate(string name)
{
	and_gate gate(name);

	and_gates.push_back(gate);
}

void board::add_or_gate(string name)
{
	or_gate gate(name);

	or_gates.push_back(gate);
}

void board::add_not_gate(string name)
{
	not_gate gate(name);

	not_gates.push_back(gate);
}

void board::add_wire(string source, string destination, string name)
{
	wire* new_wire = new wire(source, destination, name);

	if(connect_wire(new_wire))
	{
		wires.push_back(new_wire);
	}
}

int board::find_input(string name)
{
	for(unsigned int i = 0; i < inputs.size();i++)
	{
		if (inputs[i].get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

int board::find_output(string name)
{
	for(unsigned int i = 0; i < outputs.size();i++)
	{
		if (outputs[i].get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

int board::find_and_gate(string name)
{
	for(unsigned int i = 0; i < and_gates.size();i++)
	{
		if (and_gates[i].get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

int board::find_or_gate(string name)
{
	for(unsigned int i = 0; i < or_gates.size();i++)
	{
		if (or_gates[i].get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

int board::find_not_gate(string name)
{
	for(unsigned int i = 0; i < not_gates.size();i++)
	{
		if (not_gates[i].get_name() == name)
		{
			return i;
		}
	}
	return -1;
}

bool board::connect_wire(wire* wire1)
{
	//Check to see that both ends that the wire connects into are valid.

	//Connect the first end of the wire
	connect_end(wire1->get_from(), wire1);

	//Connect the second end of the wire
	connect_end(wire1->get_to(), wire1);

	return true;
}

void board::connect_end(string name, wire* wire1)
{
	int returned_index = -1;
	int counter = 0;
	int str_pos;
	string gate_name;

	//Search through all the vectors to find the source object
	while (counter  != -1 && returned_index == -1)
	{
		returned_index = -1;

		switch(counter)
		{
			case 0:
				returned_index = find_input(name);
				
				if (returned_index > -1)
				{
					inputs[returned_index].set_input_output(wire1);
					//cout << "Connected " << wire1.get_name() << " to input " << name << endl; 
				}
				
				counter++;
				break;
			case 1:
				returned_index = find_output(name);
				
				if (returned_index > -1)
				{
					outputs[returned_index].set_input_output(wire1);
					//cout << "Connected " << wire1.get_name() << " to output " << name << endl;
				}
				
				counter++;
				break;
			case 2:
				str_pos = name.find("(");
				gate_name = name.substr(0,str_pos);
				returned_index = find_and_gate(gate_name);
				
				if (returned_index > -1)
				{	
					and_gates[returned_index].set_connection(name, wire1);
					//cout << "Connected " << wire1.get_name() << " to and gate " << name << endl;
				}
				
				counter++;
				break;
			case 3:
				str_pos = name.find("(");
				gate_name = name.substr(0,str_pos);
				returned_index = find_or_gate(gate_name);
				
				if (returned_index > -1)
				{	
					or_gates[returned_index].set_connection(name, wire1);
					//cout << "Connected " << wire1.get_name() << " to or_gate " << name << endl;
				}
				
				counter++;
				break;
			case 4:
				str_pos = name.find("(");
				gate_name = name.substr(0,str_pos);
				returned_index = find_not_gate(gate_name);
				
				if (returned_index > -1)
				{	
					not_gates[returned_index].set_connection(name, wire1);
					//cout << "Connected " << wire1.get_name() << " to not gate " << name << endl;
				}

				counter++;
				break;
			case 5:
				counter = -1;
			default:
				counter = -1;
		}//end switch
	}//end while
}//end connect_end

void board::print_results()
{
	unsigned int i;
	unsigned int j;
	unsigned int iterations;
	vector<int> input_val;
	string header;
	string border;

	//number of iterations to be printed is 
	//2 ^ (# of inputs)
	iterations = inputs.size();
	iterations = int_pow(2,iterations);

	//concatenate the inputs header
	for(i = 0;i < inputs.size();i++)
	{
		header = header + inputs[i].get_name() + "    ";
		border = border + "-----";

		//init the input binary vector
		input_val.push_back(0);
	}

	header = header + "|    ";
	border = border + "-----";

	//concatenate the outputs header
	for(i = 0;i < outputs.size() - 1;i++)
	{
		header = header + outputs[i].get_name() + "    ";
		border = border + "-----";
	}

	//concatenate the final output without spaces padding 
	//the end of it
	header = header + outputs[outputs.size() - 1].get_name();
	border = border + "-";

	//print the header and border
	cout << header << endl;
	cout << border << endl;

	//print the results
	for(i = 0; i < iterations;i++)
	{
		//first print the input values
		for(j = 0;j < inputs.size();j++)
		{
			//convert the value to binary
			convert_to_binary(i, input_val);

			inputs[j].set_value(input_val[j]);

			cout << input_val[j] << "    ";
		}

		cout << "|    ";

		//print the outputs
		compute_output();
		cout << outputs[0].get_value() << endl;
	}

}

void board::convert_to_binary(int val, vector<int> &input)
{
	int remainder;
	int counter = input.size() - 1;

	while(val > 0)
	{
		remainder = val % 2;

		input[counter] = remainder;
		val = val / 2;
		counter--;
	}
}

//I created my own power function because the
//math library only lets you use power functions
//on floats and doubles
int board::int_pow(int base, int exp)
{
	int answer = 1;

	for(int i = 0;i < exp;i++)
	{
		answer = answer * base;
	}
	return answer;
}

void board::compute_output()
{
	unsigned int i;
	for(i = 0;i < and_gates.size();i++)
	{
		and_gates[i].compute_output();
	}

	for(i = 0;i < or_gates.size();i++)
	{
		or_gates[i].compute_output();
	}

	for(i = 0;i < not_gates.size();i++)
	{
		not_gates[i].compute_output();
	}
}
