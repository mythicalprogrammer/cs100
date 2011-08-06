//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>
#include "input_output.h"
#include "and_gate.h"
#include "or_gate.h"
#include "not_gate.h"
#include "wire.h"

using namespace std;

class board
{
	public:
		board();

		void parse_file(string);

		void add_input(string);
		void add_output(string);
		void add_and_gate(string);
		void add_or_gate(string);
		void add_not_gate(string);
		void add_wire(string, string, string);

		int find_input(string);
		int find_output(string);
		int find_and_gate(string);
		int find_or_gate(string);
		int find_not_gate(string);

		bool connect_wire(wire*);
		void connect_end(string, wire*);

		void print_results();
		void convert_to_binary(int, vector<int>&);
		int int_pow(int, int);
		void compute_output();

	private:
		vector <input_output> inputs;
		vector <input_output> outputs;
		vector <and_gate> and_gates;
		vector <or_gate> or_gates;
		vector <not_gate> not_gates;
		vector <wire*> wires;
};

#endif
