//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#ifndef __AND_GATE__
#define __AND_GATE__

#include <string>
#include "wire.h"

using namespace std;

class and_gate
{
	public:
		and_gate();
		and_gate(string);
		and_gate(wire*, wire*, wire*, string);

		wire* get_input0();
		wire* get_input1();
		wire* get_output();
		string get_name();

		void set_connection(string, wire*);
		void set_name(string);

		void compute_output();

	private:
		wire* input0;
		wire* input1;
		wire* output;

		string gateName;
};

#endif
