#ifndef CAS_HPP
#define CAS_HPP

#include <string>
#include <vector>
#include <regex>


#include "types.hpp"


struct regexPair
{
	std::regex reg;
	tokens::toktype type;
};


class CAS
{

	public:
		CAS (std::string input);

		void lex ();
		size_t parse (size_t tokenInd, std::unique_ptr<pTree::expr> &node);


	// initialization functions that are called by the CAS constructor
	// do not call these manually!
	private:
		void initRegexes ();

	// other functions that are used internally
	private:
		bool isExprStarterType (tokens::toktype type);

	private:
		std::vector<regexPair> m_regexPairs;

		std::string m_input;
		std::vector<tokens::token> m_tokens;
		pTree::expr m_parsedTree;


};



namespace util
{

	std::string to_string (std::vector<std::string> vec);
	std::string to_string (std::vector<tokens::token> vec);

}



#endif
