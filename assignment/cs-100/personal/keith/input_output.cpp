#include "input_output.h"
#include <string>

using namespace std;

input_output::input_output()
{
	name = "";
}

input_output::input_output(string nme)
{
	name = nme;
}

void input_output::set_input_output(wire* val)
{
	connection = val;
}

int input_output::get_value()
{
	return connection->get_value();
}


void input_output::set_value(int val)
{
	connection->set_value(val);
}

string input_output::get_name()
{
	return name;
}
