#pragma once

#include <cstdlib>
#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
	ScalarConverter();

public:
	static void convert(std::string);

	ScalarConverter(ScalarConverter&);
	ScalarConverter& operator=(ScalarConverter&);
	virtual ~ScalarConverter() = 0;
};

