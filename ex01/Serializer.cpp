/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:42 by eviscont          #+#    #+#             */
/*   Updated: 2024/11/21 14:41:50 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &other)
{
    std::cout << "Serializer copy constructor called" << std::endl;
    *this = other;
}

Serializer::~Serializer()
{
    std::cout << "Serializer destructor called" << std::endl;
}

Serializer  &Serializer::operator=(const Serializer &other)
{
    std::cout << "Serializer copy assignment operator called" << std::endl;
    (void)other;
    return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data*	Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}