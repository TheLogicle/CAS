#include "CAS.hpp"

#include <iostream>
#include <regex>
#include <stdexcept>



void CAS::lex ()
{

	const std::regex token_reg(std::string{"("} +
		+ "[0-9]+(\\.[0-9]+){0,1}" + "|" //Number
		+ "(\\+|-|\\*|/)" + "|" //Operator
	+ ")");





	for (size_t pos = 0; pos < m_input.size();) // do not put ++pos here
	{

		std::smatch res;

		std::string temp_input = m_input.substr(pos);

		std::regex_search(temp_input, res, token_reg);

		bool valid = res.length() > 0;

		if (valid)
		{
			m_tokens.push_back(res.str());

			pos += res.length();
		}
		else
		{
			throw std::runtime_error("invalid token");
		}


	}

	std::cout << util::to_string(m_tokens) << std::endl;

}


void CAS::addToken ()
{


}
