/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:21:05 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 18:02:38 by eviscont         ###   ########.fr       */
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
		static char		charVar;
		static int		intVar;
		static float	floatVar;
		static double	doubleVar;

        ScalarConverter();
        ScalarConverter(const ScalarConverter &other); //Copy constructor
        ~ScalarConverter();
        ScalarConverter  &operator=(const ScalarConverter &other); //Copy assignment operator

    public:
        static void convert(const std::string input);
};

#endif