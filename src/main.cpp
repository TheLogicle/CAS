#include <iostream>
#include <iomanip>

#include "CAS.hpp"
#include "error.hpp"


auto& prompt (std::string &input)
{
	std::cout << ">> ";
	return getline(std::cin, input);
}


int main ()
{

	std::string input;

	while (prompt(input))
	{

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
