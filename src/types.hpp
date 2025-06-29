
// this file doesn't need to be included manually
// it's already automatically included in CAS.hpp

#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>

namespace tokens
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

	struct token
	{
		tokens::toktype type;
		std::string str;
	};
}


namespace pTree
{

	struct expr;


	enum nodetype
	{
		NUMBER, OP
	};

	const std::vector<tokens::toktype> exprStarterTypes
	{
		NUMBER
	};

	// Number
	typedef float number;

	// Operator
	struct op
	{
		enum opTypes
		{
			ADD, SUBTRACT, MULTIPLY, DIVIDE
		} type;

		std::unique_ptr<expr> ex1;
		std::unique_ptr<expr> ex2;
	};
	static const std::map<std::string, op::opTypes> opMap
	{
		{"+", op::ADD},
		{"-", op::SUBTRACT},
		{"*", op::MULTIPLY},
		{"/", op::DIVIDE}
	};


	struct expr
	{
		nodetype type;

		union expr_u
		{
			number _number;
			op _op;
		} u;

		expr ();
	};

}


#endif
