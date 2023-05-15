/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:20:52 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/15 20:09:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int	ft_is_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 1;
	while (i < argc)
	{
		j = 0;
		len = ft_strlen(argv[i]);
		if (argv[i][j] == '-')
			j++;
		while (j < len)
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	ft_is_integer(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atol(argv[i]) < INT_MIN || ft_atol(argv[i]) > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_double(int argc, char **argv)
{
	int	i;
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
/*
int	main(int argc, char **argv)
{
	if (argc < 3)
		write(2, "Error (args)\n", 13); 
	if (ft_is_digit(argc, argv) == 0)
		write(2, "Error (digit)\n", 14);
	else if (!ft_is_integer(argc, argv))
		write(2, "Error (integer)\n", 16);
	else if (ft_is_double(argc, argv) == 1)
		write(2, "Error (double)\n", 15);
	return (0);
}
*/

int	ft_check_input(int argc, char **argv)
{
	if ((argc < 3) \
		|| (!ft_is_digit(argc, argv)) \
		|| (!ft_is_integer(argc, argv)) \
		|| (ft_is_double(argc, argv) == 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
