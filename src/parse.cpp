#include "CAS.hpp"

#include <iostream>
#include <memory>

#include "error.hpp"

// overload to set the default parent node to m_parsedTree
size_t CAS::parse (size_t tokenInd)
{
	return parse(tokenInd, m_parsedTree);
}

// this function will recursively parse m_tokens
// the node argument tells the function where to store its parsed result, allowing for recursion
// this function returns the index of the token AFTER the last token in the expression it just parsed (regardless of whether that token exists)
size_t CAS::parse (size_t tokenInd, pTree::exprPtr &node)
{

	std::vector<pTree::exprPtr> expressions;
	std::vector<pTree::optype> ops;

	// iterate through the tokens. it should be an alternating list of expressions and operators
	bool expectExpr = true;
	while (expectExpr)
	{

		/////// first check that there is a valid expression
		if (!tokenExists(tokenInd)) throw error::tempError("token does not exist");

		if (m_tokens.at(tokenInd).type == tokens::NUMBER)
		{

			pTree::exprPtr tempNode(new pTree::expr(pTree::NUMBER));

			tempNode->type = pTree::NUMBER;
			tempNode->u._number.val = std::stof(m_tokens.at(tokenInd).str);

			expressions.push_back(std::move(tempNode));

			++tokenInd;

		}
		else throw error::tempError("token must be a number"); // it needs to be an expression



		/////// then check if there is a valid operator

		// check again at the new token index
		if (!tokenExists(tokenInd))
		{
			expectExpr = false;
			break;
		}

		if (m_tokens.at(tokenInd).type == tokens::OP)
		{
			std::string opStr = m_tokens.at(tokenInd).str;
			pTree::optype type = pTree::opMap.at(opStr);

			ops.push_back(type);

			++tokenInd;
		}
		else
		{
			expectExpr = false;
			break;
		}

	}


	std::cout << "parsed:" << std::endl;
	std::cout << util::to_string(ops) << std::endl;
	std::cout << util::to_string(expressions) << std::endl;



	// combine the "ops" and "expressions" vectors into one whole expression,
	// taking operator precedence into account
	for (int precLevel = 0; precLevel < pTree::opPrecedence.size(); ++precLevel)
	{

		const std::vector<pTree::optype> &curOps = pTree::opPrecedence.at(precLevel);

	// here

	}



	return 0;

}


bool CAS::isExprStarterType (tokens::toktype type)
{

	for (tokens::toktype el: pTree::exprStarterTypes)
	{
		if (type == el) return true;
	}

	return false;

}

bool CAS::tokenExists (size_t tokenInd)
{

	return tokenInd < m_tokens.size();

}
