//Name       : Keith Ailshie
//Student ID : 860816418
//CS Login   : kailshie
//
//Assignment : Assignment 1
//=======================================================

#ifndef __WIRE_H__
#define __WIRE_H__

#include <string>

using namespace std;

class wire
{
	public:
		wire();
		wire(string, string, string);
		wire(string, string, string, int);

		string get_from();
		string get_to();
		string get_name();
		int get_value();

		void set_from(string);
		void set_to(string);
		void set_name(string);
		void set_value(int);

	private:
		string from;
		string to;
		string wireName;

		int value;
};

#endif
