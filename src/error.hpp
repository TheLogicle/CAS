#ifndef ERROR_HPP
#define ERROR_HPP

#include <stdexcept>


namespace error
{

	struct CASError : std::exception {};

	// this is a temporary error, only to be used for development
	// this should not ever be thrown in the final release
	struct tempError : CASError
	{
		std::string reason;
		tempError (std::string _reason) : reason {_reason} {}

		const char* what () const noexcept override
		{
			return reason.c_str();
		}
	};

	struct invalidToken : CASError
	{
		const char* what () const noexcept override
		{
			return "Invalid token";
		}
	};

}


#endif
