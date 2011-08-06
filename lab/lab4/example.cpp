#include <iostream>
#include <exception>
#include <string>

using namespace std;
/*
int main ()
	{
		try
		{
			throw 5;
		}
		
		catch (int a)
		{
			cout << "An exception occurred!" << endl;
			cout << "Exception number is: " << a << endl;
		}
		return 0;
	}

*/
int main()
{
try{
	string say;
	cout<<"Say something to the parrot don't say kirby!"<<endl;
	cin>> say;
	if(say == "kirby")
	throw 5;
	else if(say == "cracker")
	throw 6;
	cout<< say<<endl;
}
catch(int a)
{
	if(a == 5)
	cout<< "Exception!! You said kirby!" <<  endl;
	if(a == 6)
	cout<< "Cracker!! Cracker! More!"<<endl;
}
return 0;
}

