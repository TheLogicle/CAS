#include "CAS.hpp"


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

	switch (node->type)
	{

		case pTree::NUMBER:
			res = node->u._number.val;
			break;


		case pTree::OP:
			auto opFunc = pTree::optypeFuncs.at(node->u._op.type);

			float r1, r2;
			eval(node->u._op.ex1, r1);
			eval(node->u._op.ex2, r2);

			res = opFunc(r1, r2);
			break;

	}

}
