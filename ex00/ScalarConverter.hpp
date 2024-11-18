/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:05 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 00:56:59 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>

enum type { CHAR, INT, FLOAT, DOUBLE, PSEUDOLITERAL, ERROR };

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other); //Copy constructor
        ~ScalarConverter();
        ScalarConverter  &operator=(const ScalarConverter &other); //Copy assignment operator

    public:
        static void convert(const std::string input);
};

#endif