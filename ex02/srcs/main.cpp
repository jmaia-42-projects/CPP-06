/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:23:55 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:32:00 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Manipulator.hpp"

int	main(void)
{
	Base	*obj;

	srand(time(NULL));
	obj = generate();
	identify(obj);
	identify(*obj);

	delete obj;
}
