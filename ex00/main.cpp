#include "ScalarConverter.hpp"

int main(int argc, char const *argv[])
{
	// Class is not instantiable
	// ScalarConverter c;
	// (void) c;

	if (argc != 2)
		std::cout << "Error: prvide exactly one argument" << std::endl;
	else
		ScalarConverter::convert(argv[1]);
	return 0;
}
