#pragma once
#include <fstream>
#include <string>

class FileIOException
{
private:
	enum Type { INVALID_FORMAT, BAD_FILE };
	std::string _fileName;
	Type _type;
public:
	FileIOException(Type type, std::string fileName);
};

