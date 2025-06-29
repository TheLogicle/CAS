#include <iostream>

#include "CAS.hpp"
#include "error.hpp"


int main ()
{

	CAS c1("21.23-123+-/*");

	try
	{
		c1.lex();
	}
	catch (error::CASError &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

}
