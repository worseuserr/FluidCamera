#include "IO/Logger.h"
#include <format>

using namespace FluidCamera;

static tm CurrentTime()
{
	time_t				now;
	tm					current;

	now = time(nullptr);
	if (localtime_s(&current, &now) != 0)
		throw (std::exception());
	return (current);
}

Logger::Logger(const char *filename, const char *modname, const bool overwriteIfExists)
	: Out(filename, overwriteIfExists), Name(modname) {}

Logger::~Logger()
{
	Flush();
}

void Logger::Write(const char *str, LL logLevel, const bool prependDatetime, const bool appendNewline)
{
	tm	time = CurrentTime();

	Buffer << (prependDatetime ? std::format(
		"[{:02}/{:02}/{} {:02}:{:02}:{:02}] ",
		time.tm_mday,
		time.tm_mon + 1,
		time.tm_year + 1900,
		time.tm_hour,
		time.tm_min,
		time.tm_sec) : "") << LogLevelStrings[static_cast<int>(logLevel)] << str << (appendNewline ? "\n" : "");
	if (!UseBuffer || Buffer.str().size() > BufferSize)
		Flush();
}

void Logger::Write(const std::string &str, const LL logLevel, const bool prependDatetime, const bool appendNewline)
{
	Write(str.c_str(), logLevel, prependDatetime, appendNewline);
}

void Logger::Info(const std::string &str, const bool prependDatetime, const bool appendNewline)
{
	Write(str, LL::Info, prependDatetime, appendNewline);
}

void Logger::Warn(const std::string &str, const bool prependDatetime, const bool appendNewline)
{
	Write(str, LL::Warn, prependDatetime, appendNewline);
}

void Logger::Debug(const std::string &str, const bool prependDatetime, const bool appendNewline)
{
	Write(str, LL::Debug, prependDatetime, appendNewline);
}

void Logger::Error(const std::string &message)
{
	Write(message, LL::Error);
}

void Logger::Flush()
{
	if (Out.Open())
		Out << Buffer.str();
	Out.Close();
	Buffer.str("");
	Buffer.clear();
}
