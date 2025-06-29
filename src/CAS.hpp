#ifndef CAS_HPP
#define CAS_HPP

#include <string>
#include <vector>
#include <regex>


namespace type
{

	enum toktype
	{
		NUMBER, OP

	};
	const std::map<toktype, std::string> toktypeNames 
	{
		{NUMBER, "Number"},
		{OP, "Operator"}
	};
	std::string to_string (toktype type); // defined in util.cpp

	/////////////

	// Number
	typedef float number;

	// Operator
	struct op
	{
		enum opTypes
		{
			ADD, SUBTRACT, MULTIPLY, DIVIDE
		} type;
	};
	static const std::map<std::string, op::opTypes> opMap
	{
		{"+", op::ADD},
		{"-", op::SUBTRACT},
		{"*", op::MULTIPLY},
		{"/", op::DIVIDE}
	};



	// Union of all the token types to allow the parser to create a tree
	union branch_u
	{
		number _number;
		op _op;
	};

}


struct token;


struct regexPair
{
	std::regex reg;
	type::toktype type;
};


class CAS
{

	public:
		CAS (std::string input);

		void lex ();
		void parse ();


	// initialization functions that are called by the CAS constructor
	// do not call these manually!
	private:
		void initRegexes ();


	private:
		std::vector<regexPair> m_regexPairs;

		std::string m_input;
		std::vector<token> m_tokens;
		std::vector<type::branch_u> m_parsedTree;


};



namespace util
{

	std::string to_string (std::vector<std::string> vec);
	std::string to_string (std::vector<token> vec);

}




struct token
{
	type::toktype type;
	std::string str;
};


#endif
