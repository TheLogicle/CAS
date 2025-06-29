#include "CAS.hpp"

#include <vector>
#include <string>


std::string tokens::to_string (toktype type)
{
	return toktypeNames.at(type);
};


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

