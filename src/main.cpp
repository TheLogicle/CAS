#include <iostream>

#include "CAS.hpp"
#include "error.hpp"


int main ()
{

	CAS c1("2+3-1");

	try
	{
		c1.lex();
		c1.parse();
	}
	catch (error::CASError &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

}
