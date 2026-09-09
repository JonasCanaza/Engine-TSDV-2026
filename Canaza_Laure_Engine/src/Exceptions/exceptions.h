#pragma once

#include <exception>
#include <string>

class Exception
{
private:
	std::string message;
public:

	Exception(std::string message);
	~Exception();

	std::string What();
};

namespace Exceptions
{
	class OpenWindowFailed : public Exception
	{
	private:

	public:
		OpenWindowFailed(std::string message);
		~OpenWindowFailed();
	};

	class InitGlewFailed : public Exception
	{
	private:

	public:
		InitGlewFailed(std::string message);
		~InitGlewFailed();
	};

	class CreateShaderFailed : public Exception
	{
	private:

	public:
		CreateShaderFailed(std::string message);
		~CreateShaderFailed();
	};

	class CreateShaderProgramFailed : public Exception
	{
	private:

	public:
		CreateShaderProgramFailed(std::string message);
		~CreateShaderProgramFailed();
	};
}