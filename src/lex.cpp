#include "CAS.hpp"


#include "error.hpp"

#include <iostream>
#include <regex>


void CAS::initRegexes ()
{

	m_regexPairs.push_back
	({
		.reg = std::regex("^[0-9]+(\\.[0-9]+){0,1}"),
		.type = tokens::NUMBER
	});

	m_regexPairs.push_back
	({
		.reg = std::regex("^(\\+|-|\\*|/)"),
		.type = tokens::OP
	});

}


void CAS::lex ()
{


	for (size_t pos = 0; pos < m_input.size();) // do not put ++pos here
	{

		std::smatch res;

		std::string temp_input = m_input.substr(pos);

		bool validSomewhere = false;

		for (regexPair tryReg: m_regexPairs)
		{

			bool valid = std::regex_search(temp_input, res, tryReg.reg);

			if (valid)
			{
				validSomewhere = true;

				tokens::token newToken
				{
					.type = tryReg.type,
					.str = res.str()
				};

				m_tokens.push_back(newToken);
				pos += res.length();

				break;
			}

		}


		if (!validSomewhere)
		{
			throw error::invalidToken();
		}


	}

	#ifdef VERBOSE
	std::cout << "lexed:" << std::endl;
	std::cout << util::to_string(m_tokens) << std::endl;
	#endif

}

