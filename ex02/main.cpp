/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eviscont <eviscont@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:10:45 by eviscont          #+#    #+#             */
/*   Updated: 2024/11/21 17:22:54 by eviscont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

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

// void	identify(Base* p)
// {
// 	Base *a = new A();
// 	B *b = new B();
// 	C *c = new C();

// 	if (dynamic_cast<a*>(a))
// 		std::cout << "hola" << std::endl;
// }

// void	identify(Base& p)
// {

// }

int main()
{
	Base *test;
	test = generate();
	return 0;
}
