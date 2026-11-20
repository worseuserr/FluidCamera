#pragma once
#include <sstream>
#include "File.h"

// Logger and File classes from my other project (RedUI).
namespace FluidCamera
{
	enum class	LogLevel
	{
		Info,
		Warn,
		Error,
		Debug
	};

	constexpr const char	*LogLevelStrings[] =
	{
		"[INFO ] ",
		"[WARN ] ",
		"[ERROR] ",
		"[DEBUG] "
	};

	// Shorthand for LogLevel to make Write calls more concise.
	using LL = LogLevel;
}

namespace FluidCamera
{
	class Logger
	{
		File				Out;
		std::stringstream	Buffer;
		std::string			Name;

	public:
		bool			UseBuffer = false;
		unsigned int	BufferSize = 2048; // Size in characters.

		Logger(const char *filename, const char *modname, bool overwriteIfExists = true);
		~Logger();
		void	Write(const char *str, LL logLevel = LL::Info, bool prependDatetime = true, bool appendNewline = true);
		void	Write(const std::string &str, LL logLevel = LL::Info, bool prependDatetime = true, bool appendNewline = true);
		void	Error(const std::string &message);
		void	Flush();
	};
}
