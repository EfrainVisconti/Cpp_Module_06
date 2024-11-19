/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:39 by codespace         #+#    #+#             */
/*   Updated: 2024/11/19 19:34:15 by eviscont         ###   ########.fr       */
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
		ScalarConverter::_floatVar = f;
		return true;
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

static void	fromChar(char c)
{
	std::cout << "char: '" << c << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

static void	fromInt(int i)
{
	if (std::isprint(static_cast<unsigned char>(i)))
		std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << std::setprecision(1) << std::fixed;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

static void	fromFloat(float f)
{
	if (std::isprint(static_cast<unsigned char>(f)))
		std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

static void	fromDouble(double d)
{
	if (std::isprint(static_cast<unsigned char>(d)))
		std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << std::fixed;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

static void	fromPseudoliteral(std::string input)
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << input << "f" << std::endl;
	std::cout << "double: " << input << std::endl;
	//TO DO PSEUDOLITERAL FLOAT
}

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
			std::cout << "Error: invalid input value" << std::endl;
	}
}