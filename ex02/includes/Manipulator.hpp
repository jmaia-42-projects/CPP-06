/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Manipulator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 14:22:58 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:32:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANIPULATOR_HPP
# define MANIPULATOR_HPP

# include "Base.hpp"

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif
