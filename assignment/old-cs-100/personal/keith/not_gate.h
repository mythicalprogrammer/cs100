//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#ifndef __NOT_GATE_H__
#define __NOT_GATE_H__

#include <string>
#include "wire.h"

class not_gate
{
public:
		not_gate();
		not_gate(string);
		not_gate(wire*, wire*, string);

		wire* get_input0();
		wire* get_output();
		string get_name();

		void set_name(string);
		void set_connection(string, wire*);

		void compute_output();

	private:
		wire* input0;
		wire* output;

		string gateName;
};

#endif
