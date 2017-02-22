#include "FileIOException.h"

FileIOException::FileIOException(Type type, std::string fileName)
{
	_type = type;
	_fileName = fileName;
}
