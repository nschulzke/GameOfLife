#include <iostream>
#include <ctime>
#include "Life.h"
#include "Seed.h"
#include "FileIOException.h"

const int MICROS_PER_SECOND = 1000000;

int main(int arg_count, char *args[])
{
	if (arg_count != 3) {
		std::cout << "Usage: " << args[0] << " file_name number_of_steps";
		return 1;
	}

	try
	{
		Seed seed = Seed(args[1]);
		int num_steps = std::atoi(args[2]);

		Life life(seed);

		for (int i = 0; i < num_steps; i++)
		{
			std::cout << life << std::endl;
			life.step();
		}
	}
	catch (FileIOException e)
	{
		std::cout << e.toString() << std::endl;
	}
	return 0;
}