
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
	static const std::map<nodetype, std::string> nodetypeNames
	{
		{NUMBER, "Number"},
		{OP, "Operator"}
	};
	std::string to_string (nodetype type);


	// might not need this anymore
	const std::vector<tokens::toktype> exprStarterTypes
	{
		NUMBER
	};


	// Number
	struct number
	{
		float val;

		std::string to_string ();
	};

	// Operator
	enum optype
	{
		ADD, SUBTRACT, MULTIPLY, DIVIDE
	};
	static const std::map<optype, std::string> optypeNames
	{
		{ADD, "Add"},
		{SUBTRACT, "Subtract"},
		{MULTIPLY, "Multiply"},
		{DIVIDE, "Divide"}
	};
	std::string to_string (optype type);
	static const std::map<std::string, optype> opMap
	{
		{"+", ADD},
		{"-", SUBTRACT},
		{"*", MULTIPLY},
		{"/", DIVIDE}
	};
	struct op
	{
		optype type;

		std::unique_ptr<expr> ex1;
		std::unique_ptr<expr> ex2;

		std::string to_string ();
	};



	struct expr
	{
		nodetype type;

		expr (nodetype _type) : type {_type}
		{
			switch (type)
			{
				case NUMBER:
					u._number = number();
					union_to_string = &(u._number.to_string);
					break;
				case OP:
					u._op = op();
					union_to_string = &(u._op.to_string);
					break;
			}
		}

		union expr_u
		{
			number _number;
			op _op;

			expr_u(){}
			~expr_u(){}
		} u;

		std::string to_string ();
		private:
			std::string (*union_to_string) () = NULL;
	};

}


#endif
