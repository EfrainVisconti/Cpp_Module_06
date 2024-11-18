/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:19:47 by codespace         #+#    #+#             */
/*   Updated: 2024/11/18 00:07:00 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Error: invalid input format" << std::endl;
        std::cout << "Try: ./convert <value>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}