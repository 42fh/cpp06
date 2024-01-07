#include "ScalarConverter.hpp"

namespace
{
	/**
	 * returns 1 if str contains only printables, 0 otherwise
	*/
	// int containsOnlyPrint(std::string str)
	// {
	// 	for (std::string::iterator i = str.begin(); i != str.end(); i++)
	// 	{
	// 		if (isprint(*i) == 0)
	// 			return (0);
	// 	}
	// 	return (1);
	// }

	/**
	 * returns 1 if str contains only digits, 0 otherwise
	*/
	int containsOnlyDigit(std::string str)
	{
		size_t posNotDotDigit = str.find_first_not_of("0123456789");
		if (posNotDotDigit != std::string::npos)
			return (0);
		return (1);
	}

	/**
	 * returns 1 if str contains exactly one dot and digits, 0 otherwise
	*/
	int containsOneDotAndDigits(std::string str)
	{
		size_t posNotDotDigit = str.find_first_not_of(".0123456789");
		if (posNotDotDigit != std::string::npos)
			return (0);
		size_t firstDot = str.find_first_of(".");
		size_t lastDot = str.find_last_of(".");
		if (firstDot != lastDot)
			return (0);
		return (1);
	}

	/**
	 * returns:
	 * 0 for error (not a char, int, float, double)
	 * 1 for char
	 * 2 for int
	 * 3 for float
	 * 4 for double
	*/
	int detectType(std::string str)	
	{
		if (str.length() < 1)
			return (0);
		if (str.length() == 1)
		{
			if (isdigit(str[0]) != 0)
				return (2);
			else
				return (1);
		}
		if (containsOnlyDigit(str) == 1 || 
			(containsOnlyDigit(str.substr(1)) == 1 && str[0] == '-'))
			return (2);
		if (containsOneDotAndDigits(str) == 1 || 
			(containsOneDotAndDigits(str.substr(1)) == 1 && str[0] == '-'))
			return (4);
		if ((str[str.length() - 1] == 'f' && containsOneDotAndDigits(str.substr(0, str.length() - 2)) == 1) || 
			(str[str.length() - 1] == 'f' && containsOneDotAndDigits(str.substr(1, str.length() - 2)) == 1 && str[0] == '-'))
			return (3);
		if (str == "nan" || str == "-inf" || str == "+inf")
			return (4);
		if (str == "-inff" || str == "+inff" || str == "nanf")
			return (3);
		return (0);
	}

	void convertFromChar(std::string str)
	{
		char	c;
		int		i;
		float	f;
		double	d;

		c = str[0];
	
		i = static_cast<int>(c);
		f = static_cast<float>(c);
		d = static_cast<double>(c);

		if (isprint(c) == 0)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}

	void convertFromInt(std::string str)
	{
		char	c;
		int		i;
		float	f;
		double	d;

		i = atoi(str.c_str());

		c = static_cast<char>(i);
		f = static_cast<float>(i);
		d = static_cast<double>(i);

		if (d < 0 || d > 255)
			std::cout << "char: " << "impossible" << std::endl;
		else if (isprint(c) == 0)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;

		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	}

	void convertFromFloat(std::string str)
	{
		char	c;
		int		i;
		float	f;
		double	d;

		f = atof(str.c_str());

		c = static_cast<char>(f);
		i = static_cast<int>(f);
		d = static_cast<double>(f);

		if (d < 0 || d > 255)
			std::cout << "char: " << "impossible" << std::endl;
		else if (isprint(c) == 0)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;

		if (f > static_cast<float>(std::numeric_limits<int>::max()) || 
			f < static_cast<float>(std::numeric_limits<int>::min()))
			std::cout << "int: " << "impossible: overflow detected" << std::endl;
		else if (std::isnan(f) || std::isinf(f))
			std::cout << "int: " << "impossible: conversion not defined" << std::endl;
		else
			std::cout << "int: " << i << std::endl;
		
		if (f == std::floor(f))
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << "float: " << std::setprecision(10) << f << "f" << std::endl;

		if (d == std::floor(d))
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		else
			std::cout << "double: " << std::setprecision(10) << d << std::endl;
	}

	void convertFromDouble(std::string str)
	{
		char	c;
		int		i;
		float	f;
		double	d;

		d = strtod(str.c_str(), NULL);
	
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		f = static_cast<float>(d);

		if (d < 0 || d > 255 || d != d)
			std::cout << "char: " << "impossible" << std::endl;
		else if (isprint(c) == 0)
			std::cout << "char: " << "Non displayable" << std::endl;
		else
			std::cout << "char: " << c << std::endl;

		if (d != d)
			std::cout << "int: " << "impossible" << std::endl;
		else if (d > static_cast<double>(std::numeric_limits<int>::max()) || 
				 d < static_cast<double>(std::numeric_limits<int>::min()))
			std::cout << "int: " << "impossible: overflow detected" << std::endl;
		else
			std::cout << "int: " << i << std::endl;

		if (d == +std::numeric_limits<double>::infinity() || d == -std::numeric_limits<double>::infinity())
			std::cout << "float: " << std::fixed << std::setprecision(10) << f << "f" << std::endl;
		else if (d > +static_cast<double>(std::numeric_limits<float>::max()) || 
			d < -static_cast<double>(std::numeric_limits<float>::max()))
			std::cout << "float: " << "impossible: overflow detected" << std::endl;
		else if (f == std::floor(f))
			std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
		else
			std::cout << "float: " << std::fixed << std::setprecision(10) << f << "f" << std::endl;

		if (d == std::floor(d))
			std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
		else
			std::cout << "double: " << std::setprecision(10) << d << std::endl;
	}

}

void ScalarConverter::convert(std::string str)
{
	int type;

	type = detectType(str);
	if (type == 0)
		std::cout << "Error: the input \"" 
					<< str
					<<"\" provided is invalid" << std::endl;
	else if (type == 1)
		convertFromChar(str);
	else if (type == 2)
		convertFromInt(str);
	else if (type == 3)
		convertFromFloat(str);
	else if (type == 4)
		convertFromDouble(str);
}