#include "IO/File.h"
#include <filesystem>

using namespace FluidCamera;


File::File(const char *filename, const bool replaceIfExists)
	: Filename(filename)
{
	Stream.open(filename, std::ios_base::out | (replaceIfExists ? std::ios_base::trunc : std::ios_base::app));
	Stream.close();
}

bool File::Open(const std::ios_base::openmode mode)
{
	Stream.open(Filename, mode);
	return (IsOpen());
}

void File::Close()
{
	Stream.close();
}

void File::Write(const char *str)
{
	Stream << str;
}

std::string File::Read() const
{
	std::stringstream	buff;

	buff << Stream.rdbuf();
	return (std::string(buff.str()));
}

bool File::IsOpen() const
{
	return (Stream.is_open());
}

bool File::Exists(const char *filename)
{
	return (std::filesystem::exists(filename));
}
