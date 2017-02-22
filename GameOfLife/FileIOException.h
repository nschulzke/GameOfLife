#pragma once
#include <fstream>
#include <string>

class FileIOException
{
public:
	enum Type { INVALID_FORMAT, BAD_FILE };
private:
	std::string _fileName;
	Type _type;
public:
	FileIOException(Type type, std::string fileName);
	std::string toString();
	std::string fileName();
	Type type();
};

