#include "CAS.hpp"

#include <iostream>

#include "error.hpp"
#include "types.hpp"

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

			pTree::number* num = new pTree::number();

			num->val = std::stof(m_tokens.at(tokenInd).str);

			expressions.push_back(pTree::exprPtr(num));

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


	#ifdef VERBOSE
	std::cout << "parsed:" << std::endl;
	std::cout << util::to_string(ops) << std::endl;
	std::cout << util::to_string(expressions) << std::endl;
	#endif




	// combine the "ops" and "expressions" vectors into one whole expression,
	// taking operator precedence into account

	// this algorithm is a bit confusing to read, but it's simply iterating through the whole ops list,
	// processing the different operators in order of precedence
	for (int precLevel = 0; precLevel < pTree::opPrecedence.size(); ++precLevel)
	{

		const std::vector<pTree::optype> &curOps = pTree::opPrecedence.at(precLevel);



		// check each operator in the ops list
		for (int i = 0; i < ops.size(); ++i)
		{


			// iterate through the operators of this precedence level
			for (int j = 0; j < curOps.size(); ++j)
			{

				if (ops.at(i) == curOps.at(j))
				{

					pTree::exprPtr ex1, ex2;
					ex1 = std::move(expressions.at(i));
					ex2 = std::move(expressions.at(i + 1));

					expressions.erase(expressions.begin() + i);
					expressions.erase(expressions.begin() + i); // same index because everything shifted backwards

					pTree::op* combined = new pTree::op;

					combined->type = ops.at(i);

					combined->ex1 = std::move(ex1);
					combined->ex2 = std::move(ex2);

					expressions.insert(expressions.begin() + i, pTree::exprPtr(combined));

					ops.erase(ops.begin() + i);

					--i; // there is now a new element at index i because of the erase, so it must be decremented by 1

					break;

				}

			}



		}

	}


	if (expressions.size() != 1 && ops.size() != 0) throw std::runtime_error("operator precedence algorithm bug");

	#ifdef VERBOSE
	std::cout << util::to_string(expressions) << std::endl;
	#endif

	node = std::move(expressions.at(0));

	return tokenInd;

}


bool CAS::tokenExists (size_t tokenInd)
{

	return tokenInd < m_tokens.size();

}
