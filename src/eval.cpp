#include "CAS.hpp"

#include "error.hpp"

// overloads to set defaults for convenience
void CAS::eval ()
{
	eval (m_parsedTree, m_evalResult);
}

void CAS::eval (pTree::exprPtr &node)
{
	eval (node, m_evalResult);
}



void CAS::eval (pTree::exprPtr &node, float &res)
{

	if (typeid(*node) == typeid(pTree::number))
	{
		auto &numCast = dynamic_cast<pTree::number&>(*node);
		res = numCast.val;
	}
	else if (typeid(*node) == typeid(pTree::op))
	{
		auto &opCast = dynamic_cast<pTree::op&>(*node);

		float r1, r2;
		eval(opCast.ex1, r1);
		eval(opCast.ex2, r2);

		auto opFunc = pTree::optypeFuncs.at(opCast.type);

		res = opFunc(r1, r2);
	}
	else throw error::tempError("invalid type, thrown from CAS::eval");

}
