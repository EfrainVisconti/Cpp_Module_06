/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:39 by codespace         #+#    #+#             */
/*   Updated: 2024/11/20 18:49:09 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int ScalarConverter::_intVar = 0;
char ScalarConverter::_charVar = 0;
float ScalarConverter::_floatVar = 0;
double ScalarConverter::_doubleVar = 0;

ScalarConverter::ScalarConverter()
{
    std::cout << "ScalarConverter constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    *this = other;
}

ScalarConverter::~ScalarConverter()
{
    std::cout << "ScalarConverter destructor called" << std::endl;
}

ScalarConverter  &ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << "ScalarConverter copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

/* ScalarConverter::convert(input) IMPLEMENTATION */

/* Handles the case of float input and saves the value in static variable:
ScalarConverter::_floatVar */
static bool	floatTypeCase(std::string input)
{
	float f;
    std::string nbr = input.substr(0, input.length() - 1);
    std::istringstream floatStream(nbr);
    floatStream >> f;
    if (!floatStream.fail() && floatStream.eof())
	{
		if (f >= std::numeric_limits<float>::min() && f <= std::numeric_limits<float>::max())
		{
			ScalarConverter::_floatVar = f;
			return true;
		}
	}
	return false;
}

/* Handles the case of double input and saves the value in static variable:
ScalarConverter::_doubleVar */
static bool	doubleTypeCase(std::string input)
{
    double d;
    std::istringstream doubleStream(input);
    doubleStream >> d;
    if (!doubleStream.fail() && doubleStream.eof())
	{
		ScalarConverter::_doubleVar = d;
        return true;
	}
	return false;
}

/* Handles the case of int input and saves the value in static variable:
ScalarConverter::_intVar */
static bool	intTypeCase(std::string input)
{
	int i;
    std::istringstream intStream(input);
    intStream >> i;
    if (!intStream.fail() && intStream.eof())
	{
		ScalarConverter::_intVar = i;
        return true;
	}
	return false;
}

/* Checks input type between all options, following a logic order to guarantee correct
choice: char type ('c' format), pseudoliteral type (nan, nanf, +inf, +inff...), float type (0.0f format),
double type (0.0 format) or int type (0 format). */
static type inputType(std::string input)
{
	if (input.size() == 1 && !std::isdigit(input[0]))
	{
		ScalarConverter::_charVar = input[0];
        return CHAR;
	}

    if (input == "nan" || input == "+inf" || input == "-inf"
        || input == "nanf" || input == "+inff" || input == "-inff")
        return PSEUDOLITERAL;

    if (*(input.end() - 1) == 'f' && input.find('.') != std::string::npos
		&& floatTypeCase(input))
		return FLOAT;

    if (input.find('.') != std::string::npos && doubleTypeCase(input))
		return DOUBLE;

    if (intTypeCase(input))
        return INT;

    return ERROR;
}

/* Prints the casts when the input was of type char, following the format required in the subject */
static void	fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

/* Prints the casts when the input was of type int, following the format required in the subject */
static void	fromInt(int i)
{
	if (i >= 32 && i <= 126)
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

/* Prints the casts when the input was of type float, following the format required in the subject */
static void	fromFloat(float f)
{
	if (f >= 32 && f <= 126)
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (f >= std::numeric_limits<int>::min() && f <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

/* Prints the casts when the input was of type double, following the format required in the subject */
static void	fromDouble(double d)
{
	if (d >= 32 && d <= 126)
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (d >= std::numeric_limits<int>::min() && d <= std::numeric_limits<int>::max())
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

/* Prints the casts when special inputs occurs (called pseudoliterals), following the format required in the subject */
static void	fromPseudoliteral(std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (input == "nanf" || input == "+inff" || input == "-inff")
	{
		std::cout << "float: " << input << std::endl;
		std::cout << "double: " << input.substr(0, input.length() - 1) << std::endl;
		return ;
	}
	std::cout << "float: " << input + "f" << std::endl;
	std::cout << "double: " << input << std::endl;
}

/* Main static method required for ScalarConverter class
WARNING: if input uses a specific format type (as explained in subject) but has a
number out of that range, it will gives you an error message. For example:
-'ñ' (valid char format, out of ASCII printable characters range)
-3.5e39f (valid float format, value out of float range).
-2147483648 (valid int format, value out of int range).
-1.8e308 (valid double format, value out of double range).*/
void    ScalarConverter::convert(const std::string input)
{
    switch (inputType(input))
	{
		case CHAR:
			fromChar(ScalarConverter::_charVar);
            break ;
		case INT:
			fromInt(ScalarConverter::_intVar);
            break ;
		case FLOAT:
			fromFloat(ScalarConverter::_floatVar);
            break ;
		case DOUBLE:
			fromDouble(ScalarConverter::_doubleVar);
			break ;
        case PSEUDOLITERAL:
			fromPseudoliteral(input);
			break ;
		default:
			std::cout << "Error: invalid format or " << std::endl;
			std::cout << "value out of range for input type" << std::endl;
	}
}