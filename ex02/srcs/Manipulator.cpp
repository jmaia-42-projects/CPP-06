/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manipulator.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:25:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:41:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Manipulator.hpp"

#include <cstdlib>
#include <iostream>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void)
{
	switch (rand() % 3)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
	}
	return (0);
}

void	identify(Base *p)
{
	A	*a;
	B	*b;
	C	*c;

	a = dynamic_cast<A*>(p);
	b = dynamic_cast<B*>(p);
	c = dynamic_cast<C*>(p);
	if (a)
		std::cout << "A" << std::endl;
	else if (b)
		std::cout << "B" << std::endl;
	else if (c)
		std::cout << "C" << std::endl;
	else
		std::cout << "UNKNWON" << std::endl;
}

void	identify(Base &p)
{
	A	a;
	B	b;
	C	c;

	try
	{
		a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (const std::exception &e)
	{
		try
		{
			b = dynamic_cast<B&>(p);
			std::cout << "B" << std::endl;
		}
		catch (const std::exception &e)
		{
			try
			{
				c = dynamic_cast<C&>(p);
				std::cout << "C" << std::endl;
			}
			catch (const std::exception &e)
			{
				std::cout << "UNKNOWN" << std::endl;
			}

		}

	}
}
