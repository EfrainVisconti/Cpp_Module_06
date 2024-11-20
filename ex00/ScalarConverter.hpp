/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:05 by codespace         #+#    #+#             */
/*   Updated: 2024/11/20 17:30:21 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <limits>

enum type { CHAR, INT, FLOAT, DOUBLE, PSEUDOLITERAL, ERROR };

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other); //Copy constructor
        ~ScalarConverter();
        ScalarConverter  &operator=(const ScalarConverter &other); //Copy assignment operator

    public:
		static char		_charVar;
		static int		_intVar;
		static float	_floatVar;
		static double	_doubleVar;

        static void convert(const std::string input);
};

#endif