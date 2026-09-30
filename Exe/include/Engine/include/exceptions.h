#pragma once

#include <exception>
#include <string>

#include "Defines/dll_define.h"

#pragma warning(push)
#pragma warning(disable: 4251)

namespace Exceptions
{
	class ENGINE_API Exception
	{
	private:
		std::string message;
	public:

		Exception(std::string message);
		virtual ~Exception();

		const char* What() { return message.c_str(); }
	};

	class ENGINE_API OpenWindowFailed : public Exception
	{
	private:

	public:
		OpenWindowFailed(std::string message);
		~OpenWindowFailed();
	};

	class ENGINE_API InitGlewFailed : public Exception
	{
	private:

	public:
		InitGlewFailed(std::string message);
		~InitGlewFailed();
	};

	class ENGINE_API CreateShaderFailed : public Exception
	{
	private:

	public:
		CreateShaderFailed(std::string message);
		~CreateShaderFailed();
	};

	class ENGINE_API CreateShaderProgramFailed : public Exception
	{
	private:

	public:
		CreateShaderProgramFailed(std::string message);
		~CreateShaderProgramFailed();
	};

	class ENGINE_API EngineInitFailed : public Exception
	{
	private:

	public:
		EngineInitFailed(std::string message);
		~EngineInitFailed();
	};
}

