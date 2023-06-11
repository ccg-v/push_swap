/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:20:52 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/11 21:16:00 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
long ft_atol(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
*/

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_integer(char *str)
{
	if (ft_atol(str) >= INT_MIN && ft_atol(str) <= INT_MAX)
		return (1);
	return (0);
}

int	ft_is_double(int argc, char **argv)
{
	int i;
	int	j;
	int	num1;
	int	num2;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			num1 = ft_atol(argv[i]);
			num2 = ft_atol(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
		while (j < len)
		{
			if (!ft_is_digit(argv[i][j]))
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		if (!ft_is_integer(argv[i]))
			write(2, "Error\n", 6);
		else
			write(2, "Ok\n", 3);	
		i++;
	}
	if (ft_is_double(argc, argv) == 1)
		printf("Is double!\n");
	return (0);
}
