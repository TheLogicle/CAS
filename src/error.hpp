#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>


namespace error
{

	struct CASError : std::exception {};

	struct invalidToken : CASError
	{
		const char* what () const noexcept override
		{
			return "Invalid token";
		}
	};

}


#endif
