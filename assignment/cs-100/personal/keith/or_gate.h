//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#ifndef __OR_GATE_H__
#define __OR_GATE_H__

#include <string>
#include "wire.h"

class or_gate
{
	public:
		or_gate();
		or_gate(string);
		or_gate(wire*, wire*, wire*, string);

		wire* get_input0();
		wire* get_input1();
		wire* get_output();
		string get_name();

		void set_name(string);
		void set_connection(string, wire*);

		void compute_output();

	private:
		wire* input0;
		wire* input1;
		wire* output;

		string gateName;
};

#endif
