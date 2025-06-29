#include "CAS.hpp"

#include <vector>
#include <string>

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
