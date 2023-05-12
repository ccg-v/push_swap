/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:12:04 by ccarrace          #+#    #+#             */
/*   Updated: 2023/05/09 20:20:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* LIBRARY <stddef.h>
 *
 * DESCRIPTION
 * Converts the initial portion of the string pointed to by 'str' to 'int'.
 *
 * COMMENTS
 * First of all the function skips possible white spaces at the beginning of 
 * the string:
 * 		9 ht (horizontal tab) | 10 nl (newline) | 11 vl (vertical tab)
 * 		  12 np (new page) | 13 cr (carriage return) | 32 sp (space)
 *
 * Then it handles the sign, if found. Either if its negative or positive, the
 * function will skip it, but if negative it will be held in a variable 'sign'.
 *
 * Next, it manages the conversion. If a digit is found the function starts
 * a loop until it finds a char. Multiplication by ten is used as placeholder,
 * and char is converted to int by substracting 0's ascii value'.
 *
 * Finally, when returning the value the sign is retrieved.
 */

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = (sign * -1);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}

#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argc;
	printf("%d\n", ft_atoi(argv[1]));
	return (0);
}
