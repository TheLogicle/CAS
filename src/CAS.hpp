#ifndef CAS_HPP
#define CAS_HPP

#include <string>
#include <vector>


class CAS
{

	public:
		CAS (std::string input);

		void lex ();

	private:
		void addToken ();

	private:
		std::string m_input;

		std::vector<std::string> m_tokens;

};



namespace util
{

	std::string to_string (std::vector<std::string> vec);

}




namespace type
{

	typedef float number;


	struct op
	{

		enum
		{
			ADD, SUBTRACT, DIVIDE, MULTIPLY
		} type;

	};

}


#endif
