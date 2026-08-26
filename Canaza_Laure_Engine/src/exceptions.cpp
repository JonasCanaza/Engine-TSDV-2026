#include "exceptions.h"

Exception::Exception(std::string message)
{
	this->message = message;
}

Exception::~Exception()
{
	
}

std::string Exception::What()
{
	return message;
}

namespace Exceptions
{
	OpenWindowFailed::OpenWindowFailed(std::string message) : Exception(message)
	{

	}

	OpenWindowFailed::~OpenWindowFailed()
	{

	}

	InitGlewFailed::InitGlewFailed(std::string message) : Exception(message)
	{

	}

	InitGlewFailed::~InitGlewFailed()
	{

	}
}