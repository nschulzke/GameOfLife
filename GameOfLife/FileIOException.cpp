#include "FileIOException.h"

FileIOException::FileIOException(Type type, std::string fileName)
{
	_type = type;
	_fileName = fileName;
}

std::string FileIOException::toString()
{
	if (_type == INVALID_FORMAT)
		return "Invalid file format in file: " + _fileName;
	else
		return "Unable to open file: " + _fileName;
}
