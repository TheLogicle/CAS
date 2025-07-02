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
		size_t parse (size_t tokenInd = 0); // default node is m_parsedTree
		size_t parse (size_t tokenInd, pTree::exprPtr &node);
		void eval (); // default node is m_parsedTree, default res is m_evalResult
		void eval (pTree::exprPtr &node); // default res is m_evalResult
		void eval (pTree::exprPtr &node, double &res);

		std::string& getInput();
		std::vector<tokens::token>& getTokens();
		std::unique_ptr<pTree::expr>& getParsedTree();
		double getEvalResult ();



	private:
		// other functions that are used internally
		bool tokenExists (size_t tokenInd);


		// internal lexing regexes
		const std::vector<regexPair> m_regexPairs
		{
			{
				.reg = std::regex("^[0-9]+(\\.[0-9]+){0,1}"),
				.type = tokens::NUMBER
			},
			{
				.reg = std::regex("^(\\+|-|\\*|/)"),
				.type = tokens::OP
			}
		};

		std::string m_input;
		std::vector<tokens::token> m_tokens;
		pTree::exprPtr m_parsedTree = nullptr;
		double m_evalResult = 0;


};



namespace util
{

	std::string to_string (std::vector<std::string> vec);
	std::string to_string (std::vector<tokens::token> vec);
	std::string to_string (std::vector<pTree::optype> vec);
	std::string to_string (std::vector<pTree::exprPtr> &vec);

}



#endif
