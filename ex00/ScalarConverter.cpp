/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:39 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 02:41:48 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//./convert 0
//char: Non displayable
//int: 0
//float: 0.0f
//double: 0.0
//./convert nan
//char: impossible
//int: impossible
//float: nanf
//double: nan
//./convert 42.0f
//char: '*'
//int: 42
//float: 42.0f
//double: 42.0

#include "ScalarConverter.hpp"

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

static type inputType(std::string input)
{
    int i;
    std::istringstream intStream(input);
    intStream >> i;
    if (!intStream.fail() && intStream.eof())
        return INT;

    if (input == "nan" || input == "+inf" || input == "-inf"
        || input == "nanf" || input == "+inff" || input == "-inff")
        return PSEUDOLITERAL;

    if (input.size() == 3 && input[0] == '\'' && input[2] == '\'')
        return CHAR;

    if (*(input.end() - 1) == 'f' && input.find('.') != std::string::npos)
    {
        float f;
        std::string nbr = input.substr(0, input.length() - 1);
        std::istringstream floatStream(nbr);
        floatStream >> f;
        if (!floatStream.fail() && floatStream.eof())
            return FLOAT;
    }

    if (input.find('.') != std::string::npos)
    {
        double d;
        std::istringstream doubleStream(input);
        doubleStream >> d;
        if (!doubleStream.fail() && doubleStream.eof())
        return DOUBLE;
    }

    return ERROR;
}

void    ScalarConverter::convert(std::string input)
{
    switch (inputType(input))
	{
		case CHAR:
			std::cout << "char" << std::endl;
            break ;
		case INT:
			std::cout << "int" << std::endl;
            break ;
		case FLOAT:
			std::cout << "float" << std::endl;
            break ;
		case DOUBLE:
			std::cout << "double" << std::endl;
			break ;
        case PSEUDOLITERAL:
			std::cout << "pseudoliteral" << std::endl;
			break ;
		default:
			std::cout << "error" << std::endl;
	}
}