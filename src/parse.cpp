#include "CAS.hpp"

#include <memory>

// this function will recursively parse m_tokens
// the node argument tells the function where to store its parsed result, allowing for recursion
// this function returns the index of the token AFTER the last token in the expression it just parsed (regardless of whether that token exists)
size_t CAS::parse (size_t tokenInd, std::unique_ptr<pTree::expr> &node)
{

	node = std::unique_ptr<pTree::expr>(new pTree::expr);

	std::vector<pTree::expr> expressions;

	if (m_tokens.at(tokenInd).type == tokens::NUMBER)
	{
		std::unique_ptr<pTree::expr> tempNode;

		node->type = pTree::NUMBER;
		node->u._number = 

	}
	else throw 1; // it needs to be an expression // change this to throw an actual error

}


bool CAS::isExprStarterType (tokens::toktype type)
{

	for (tokens::toktype el: pTree::exprStarterTypes)
	{
		if (type == el) return true;
	}

	return false;

}
