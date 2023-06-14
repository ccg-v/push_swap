/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:20:52 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/15 00:23:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_digit(int argc, char **argv)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (i < argc)
	{
		j = 0;
		if (!argv[i][j])
			return (0);
		len = ft_strlen(argv[i]);
		if (argv[i][j] == '-' && argv[i][j + 1])
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

	i = 0;
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

	i = 0;
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
	--- ft_split_if_quoted_args() ----------------------------------------------
	
	  - If the argument has been submitted within quotes (argc == 2), I split it.
	  	The first element will be arg[0], the second will be arg[1], and so on.
	  - If the argument has no quotes, or it is empty (""), or just one digit 
	  	(like 'a' or '0', no matter if it is quoted or not), I change 'argv' and 
		'argc' in order to skip the name of the program, which is initially the 
		arg[0]), and assign instead the '0' index to the first element. I need 
		this coherence, otherwise for instance if a loop start iterating from 
		i = 0, in a splitted argument it will start from the first element, but 
		in a normal sequence of non-quoted arguments it will start from the 
		program's name.
*/
void	ft_split_if_quoted_args(int *argc, char ***argv)
{
	char	*str;

	if (*argc == 2 && ft_strlen((*argv)[1]) > 1)
	{
		str = (*argv)[1];
		*argv = ft_split(str, ' ');
		*argc = ft_word_counter(str, ' ');
	}
	else
	{
		(*argv)++;
		(*argc)--;
	}	
}

int	ft_check_input(int argc, char **argv)
{
	if (argc == 1 && ft_is_digit(argc, argv) && ft_is_integer(argc, argv))
		return (0);
	if ((!ft_is_digit(argc, argv)) \
		|| (!ft_is_integer(argc, argv)) || (ft_is_double(argc, argv) == 1))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
