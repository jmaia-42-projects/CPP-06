/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:11:51 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:19:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Data.hpp"

int	main(void)
{
	Data		*data;
	Data		*dataReturned;
	uintptr_t	raw;

	data = new Data();
	data->data = 42;
	raw = serialize(data);
	dataReturned = deserialize(raw);
	std::cout << data << std::endl;
	std::cout << dataReturned << std::endl;
	std::cout << data->data << std::endl;
	std::cout << dataReturned->data << std::endl;
	delete data;
}
