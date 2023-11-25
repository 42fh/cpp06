#include "ScalarConverter.hpp"

namespace
{
	/**
	 * returns 1 if str contains only printables, 0 otherwise
	*/
	int containsOnlyPrint(std::string str)
	{
		for (std::string::iterator i = str.begin(); i != str.end(); i++)
		{
			if (isprint(*i) == 0)
				return (0);
		}
		return (1);
	}

	/**
	 * returns 1 if str contains only digits, 0 otherwise
	*/
	int containsOnlyDigit(std::string str)
	{
		for (std::string::iterator i = str.begin(); i != str.end(); i++)
		{
			if (isdigit(*i) == 0)
				return (0);
		}
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
		if (containsOnlyPrint(str) != 1)
			return (0);
		if (str.length() == 1)
		{
			if (isdigit(str[0]) != 0)
				return (2);
			else if (isprint(str[0]) != 0)
				return (1);
			else
				return (0);
		}
		if (containsOnlyDigit(str) == 1 || 
			(str[0] == '-' && containsOnlyDigit(str.substr(1)) == 1))
			return (2);
		if (containsOneDotAndDigits(str) == 1)
			return (4);
		if (containsOneDotAndDigits(str.substr(0, str.length() - 1)) == 1)
			return (3);
		if (str == "nan" || str == "-inf" || str == "+inf")
			return (4);
		if (str == "-inff" || str == "+inff")
			return (3);
		return (0);
	}

	void outputdifd(char c, int i, float f, double d)
	{
		std::cout << "char: " << c << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
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

		outputdifd(c, i, f, d);
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

		outputdifd(c, i, f, d);
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

		outputdifd(c, i, f, d);
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

		outputdifd(c, i, f, d);
	}

}

void ScalarConverter::convert(std::string str)
{
	int type;

	type = detectType(str);
	if (type == 0)
		std::cout << "Error: the input provided is invalid" << std::endl;
	else if (type == 1)
		convertFromChar(str);
	else if (type == 2)
		convertFromInt(str);
	else if (type == 3)
		convertFromFloat(str);
	else if (type == 4)
		convertFromDouble(str);
}