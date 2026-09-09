#include "Exceptions/exceptions.h"

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
	OpenWindowFailed::OpenWindowFailed(std::string message) : Exception(message) {}
	OpenWindowFailed::~OpenWindowFailed() {}

	InitGlewFailed::InitGlewFailed(std::string message) : Exception(message) {}
	InitGlewFailed::~InitGlewFailed() {}

	CreateShaderFailed::CreateShaderFailed(std::string message) : Exception(message) {}
	CreateShaderFailed::~CreateShaderFailed() {}

	CreateShaderProgramFailed::CreateShaderProgramFailed(std::string message) : Exception(message) {}
	CreateShaderProgramFailed::~CreateShaderProgramFailed() {}
}