#include "CAS.hpp"

CAS::CAS (std::string input)
	: m_input {input}
{}


std::string& CAS::getInput ()
{
	return m_input;
}

std::vector<tokens::token>& CAS::getTokens ()
{
	return m_tokens;
}

std::unique_ptr<pTree::expr>& CAS::getParsedTree ()
{
	return m_parsedTree;
}

double CAS::getEvalResult ()
{
	return m_evalResult;
}
