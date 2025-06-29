#include "CAS.hpp"


void CAS::parse ()
{

	for (token tok: m_tokens)
	{


		type::branch_u branch;

		switch (tok.type)
		{

			case type::NUMBER:
				branch._number = std::stof(tok.str);
				break;

			case type::OP:
				break;

			default:
				throw std::runtime_error("Invalid token type, thrown from CAS::parse");

		}

	}

}
