/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:10:45 by eviscont          #+#    #+#             */
/*   Updated: 2024/11/23 17:34:14 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

class InvalidCastException : public std::exception
{

};

Base*	generate(void)
{
	Base* result;
	std::srand(std::time(0));
    int random = 1 + (std::rand() % 3);

	if (random == 1)
		result = new A();
	else if (random == 2)
		result = new B();
	else
		result = new C();
	return result;
}

void	identify(Base* p)
{
	if (!p)
		std::cout << "NULL" << std::endl;
	else if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void	identify(Base& p)
{
	try
	{
		if (dynamic_cast<A*>(&p))
		{
			std::cout << "A" << std::endl;
			return;
        }
		else
            throw InvalidCastException();
	}
	catch (const InvalidCastException&) {}
	try
	{
        if (dynamic_cast<B*>(&p))
		{
			std::cout << "B" << std::endl;
            return;
		}
		else
			throw InvalidCastException();
	}
	catch (const InvalidCastException&) {}
	try
	{
		if (dynamic_cast<C*>(&p))
		{
			std::cout << "C" << std::endl;
			return;
		}
		else
			throw InvalidCastException();
	}
	catch (const InvalidCastException&) {}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::cout << "Testing generate function" << std::endl;
	Base *test = generate();
	identify(test);
	std::cout << "Testing identify functions" << std::endl;
	std::cout << "Case A:" << std::endl;
	Base *test1 = new A();
	identify(test1);
	identify(*test1);
	std::cout << "Case B:" << std::endl;
	Base *test2 = new B();
	identify(test2);
	identify(*test2);
	std::cout << "Case C:" << std::endl;
	Base *test3 = new C();
	identify(test3);
	identify(*test3);
	std::cout << "Case NULL:" << std::endl;
	identify(NULL);
	delete test;
	delete test1;
	delete test2;
	delete test3;
	return 0;
}
