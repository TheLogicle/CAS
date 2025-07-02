
// this file doesn't need to be included manually
// it's already automatically included in CAS.hpp

#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>
#include <stdexcept>
#include <functional>

#include <iostream>

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

	struct expr
	{
		virtual std::string to_string ();
	};

	typedef std::unique_ptr<expr> exprPtr;



	// Number
	struct number : expr
	{
		double val;

		virtual std::string to_string ();
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
	static const std::map<optype, std::function<double (double, double)>> optypeFuncs
	{
		{ADD, [](double a, double b) { return a + b; }},
		{SUBTRACT, [](double a, double b) { return a - b; }},
		{MULTIPLY, [](double a, double b) { return a * b; }},
		{DIVIDE, [](double a, double b) { return a / b; }}
	};
	static const std::map<std::string, optype> opMap
	{
		{"+", ADD},
		{"-", SUBTRACT},
		{"*", MULTIPLY},
		{"/", DIVIDE}
	};
	// first element in outer vector has highest precedence
	static const std::vector<std::vector<optype>> opPrecedence
	{
		{MULTIPLY, DIVIDE},
		{ADD, SUBTRACT}
	};
	std::string to_string (optype type);

	struct op : expr
	{
		optype type;

		exprPtr ex1 = nullptr;
		exprPtr ex2 = nullptr;

		virtual std::string to_string ();
	};


}


#endif
