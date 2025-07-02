#include <iostream>
#include <iomanip>

#include "CAS.hpp"
#include "error.hpp"


int main ()
{

	while (true)
	{

		std::cout << ">> ";
		std::string input;
		std::cin >> input;

		if (input == "exit") return 0;

		CAS c1(input);

		try
		{
			c1.lex();
			c1.parse();
			c1.eval();

			std::cout << std::setprecision(10) << c1.getEvalResult() << std::endl;
		}
		catch (error::CASError &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
		}
	
	}

}
