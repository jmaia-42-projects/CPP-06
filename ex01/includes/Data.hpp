/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:09:38 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:18:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP

# include <stdint.h>

typedef struct Data
{
	int	data;
}	Data;

uintptr_t	serialize(Data *ptr);
Data		*deserialize(uintptr_t raw);

#endif
