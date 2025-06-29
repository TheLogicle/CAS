#include "CAS.hpp"
#include "types.hpp"

#include <vector>
#include <string>


std::string tokens::to_string (toktype type)
{
	return toktypeNames.at(type);
};

std::string pTree::to_string (nodetype type)
{
	return nodetypeNames.at(type);
}

std::string pTree::to_string (optype type)
{
	return optypeNames.at(type);
}



std::string pTree::expr::to_string ()
{
	return "{" + pTree::to_string(type) + ", " + union_to_string(*this) + "}";
}



std::string pTree::number::to_string ()
{
	return std::to_string(val);
}
std::string pTree::number::to_string_st (pTree::expr &ex) { return ex.u._number.to_string(); }


std::string pTree::op::to_string ()
{
	return pTree::to_string(type) + ", " + ex1->to_string() + ", " + ex2->to_string();
}
std::string pTree::op::to_string_st (pTree::expr &ex) { return ex.u._op.to_string(); }





std::string util::to_string (std::vector<std::string> vec)
{

	std::string res = "[";

	for (size_t i = 0; i < vec.size(); ++i)
	{
		res += "\"" + vec.at(i) + "\"";

		if (i < vec.size() - 1)
		{
			res += ", ";
		}
	}

	res += "]";

	return res;

}


std::string util::to_string (std::vector<tokens::token> vec)
{

	std::string res = "[\n";

	for (size_t i = 0; i < vec.size(); ++i)
	{
		tokens::token &el = vec.at(i);

		res += "  {" + el.str + ", " + tokens::to_string(el.type) + "}";

		if (i < vec.size() - 1)
		{
			res += ",";
		}

		res += "\n";
	}

	res += "]";

	return res;

}


std::string util::to_string (std::vector<pTree::optype> vec)
{

	std::string res = "[";

	for (size_t i = 0; i < vec.size(); ++i)
	{
		pTree::optype &el = vec.at(i);

		res += pTree::to_string(el);

		if (i < vec.size() - 1)
		{
			res += ", ";
		}
	}

	res += "]";

	return res;

}


std::string util::to_string (std::vector<pTree::exprPtr> &vec)
{

	std::string res = "[\n";

	for (size_t i = 0; i < vec.size(); ++i)
	{
		pTree::exprPtr &el = vec.at(i);

		res += "  " + el->to_string();

		if (i < vec.size() - 1)
		{
			res += ",";
		}

		res += "\n";

	}

	res += "]";

	return res;

}
