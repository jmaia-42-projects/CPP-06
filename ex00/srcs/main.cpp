/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 11:08:59 by jmaia             #+#    #+#             */
/*   Updated: 2022/06/03 14:04:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>

static bool		isDecimal(std::string str);
static double	toDouble(std::string str);
static void		printCharConversion(double dValue);
static bool		isNan(double dValue);
static void		printIntConversion(double dValue);
static void		printFloatConversion(double dValue);
static bool		contains(std::string haystack, char c);
static void		printDoubleConversion(double dValue);

int	main(int ac, char **av)
{
	double		dValue;
	std::string	str;

	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <str_representation>" << std::endl;
		return (1);
	}
	str = std::string(av[1]);
	dValue = toDouble(str);
	if (!isDecimal(str) && str.length() > 1 && !isNan(dValue) && dValue != -INFINITY && dValue != +INFINITY)
	{
		std::cout <<	"char: impossible\n"
		   				"int: impossible\n"
						"float: impossible\n"
						"double: impossible" << std::endl;
		return (0);
	}
	printCharConversion(dValue);
	printIntConversion(dValue);
	printFloatConversion(dValue);
	printDoubleConversion(dValue);
}

static bool		isDecimal(std::string str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
	}
	if (str[i] == 'f')
		i++;
	return (!str[i]);
}

static double	toDouble(std::string str)
{
	std::istringstream	ss(str);
	double				dValue;

	if (str.length() == 1 && !(str[0] >= '0' && str[0] <= '9'))
		dValue = static_cast<char>(str[0]);
	else
	{
		std::string	keys[4] = {"-inf", "+inf", "inf", "nan"};
		double		values[4] = {-INFINITY, +INFINITY, INFINITY, NAN};
		for (int i = 0; i < 4; i++)
		{
			if (keys[i] == str || keys[i] + 'f' == str)
			{
				return (values[i]);
			}
		}
		ss >> dValue;
	}
	return (dValue);
}

static void	printCharConversion(double dValue)
{
	char	c;

	if (isNan(dValue) || isinf(dValue) || dValue < 0)
		std::cout << "char: impossible" << std::endl;
	else if (dValue < 32 || dValue > 126)
		std::cout << "char: Non displayable" << std::endl;
	else
	{
		c = static_cast<char>(dValue);
		std::cout << "char: '" << c << "'" <<  std::endl;
	}
}

static bool	isNan(double dValue)
{
	return (dValue != dValue);
}

static void	printIntConversion(double dValue)
{
	int	i;

	if (isNan(dValue) || dValue == +INFINITY || dValue == -INFINITY)
		std::cout << "int: impossible" << std::endl;
	else
	{
		i = static_cast<int>(dValue);
		std::cout << "int: " << i << std::endl;
	}
}

static void	printFloatConversion(double dValue)
{
	float				f;
	std::string			str;
	std::ostringstream	oss;

	f = static_cast<float>(dValue);
	oss << f;
	str = oss.str();
	if (!contains(str, '.') && !isNan(dValue) && dValue != -INFINITY && dValue != +INFINITY)
		str += ".0";
	std::cout << "float: " << str << "f" << std::endl;
}

static bool	contains(std::string haystack, char c)
{
	for (unsigned int i = 0; i < haystack.length(); i++)
		if (haystack[i] == c)
			return (true);
	return (false);
}

static void	printDoubleConversion(double dValue)
{
	std::ostringstream	oss;
	std::string			str;

	oss << dValue;
	str = oss.str();
	if (!contains(str, '.') && !isNan(dValue) && dValue != -INFINITY && dValue != +INFINITY)
		str += ".0";
	std::cout << "double: " << str << std::endl;
}
