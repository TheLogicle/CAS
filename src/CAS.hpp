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
		size_t parse (size_t tokenInd = 0);
		size_t parse (size_t tokenInd, std::unique_ptr<pTree::expr> &node);

		std::string& getInput();
		std::vector<tokens::token>& getTokens();
		std::unique_ptr<pTree::expr>& getParsedTree();


	private:
		// initialization functions that are called by the CAS constructor
		// do not call these manually!
		void initRegexes ();


		// other functions that are used internally
		bool isExprStarterType (tokens::toktype type); // might not need this anymore
		bool tokenExists (size_t tokenInd);


		// internal processing data
		std::vector<regexPair> m_regexPairs;

		std::string m_input;
		std::vector<tokens::token> m_tokens;
		pTree::exprPtr m_parsedTree;


};



namespace util
{

	std::string to_string (std::vector<std::string> vec);
	std::string to_string (std::vector<tokens::token> vec);
	std::string to_string (std::vector<pTree::optype> vec);
	std::string to_string (std::vector<pTree::exprPtr> &vec);

}



#endif
