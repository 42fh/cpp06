#include "ScalarConverter.hpp"

namespace
{
	void testfunction(void)
	{
		std::cout << "Hello" << std::endl;
	}
}

void ScalarConverter::convert(std::string str)
{
	testfunction();

	double a = strtod("0.5123456789", NULL);
	float  b = strtof("0.5123456789", NULL);

	std::cout << atof(str.c_str()) * 0.5 << std::endl;
	std::cout << atoi(str.c_str()) * 0.5 << std::endl;
	std::cout << strtod(str.c_str(), NULL) * 0.5 << std::endl;
	std::cout << std::setprecision (30) << a << std::endl;
	std::cout << std::setprecision (30) << b << std::endl;

}