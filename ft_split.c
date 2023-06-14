/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 00:03:33 by ccarrace          #+#    #+#             */
/*   Updated: 2023/06/13 18:35:36 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESCRIPTION
 * Allocates and returns an array of strings obtained by splitting 's' using the
 * character 'c' as a delimiter. The array must end with a NULL pointer.
 *
 * PARAMETERS
 * s:	The string to be split.
 * c:	The delimiter character.
 *
 * EXTERNAL FUNCTIONS
 * malloc(), free()
 *
 * RETURN VALUES
 * The array of new strings resulting from the split or NULL if allocation fails
 * 
 * COMMENTS
 * 1. Create a function to count the number of words contained in the string
 * 		Parameters: The string 'str'
 * 					The delimiter character 'c'
 * 2. Create a function to find out each word's length
 * 		Parameters: The string 'str'
 * 					The delimiter character 'c'
 * 					The starting character 'i'
 * 3. Create a function to free memory if allocation fails
 * 4. We begin allocating a block of memory with (num of words + 1) to save 
 * 	  pointers to each word.
 *    Next we start a loop to create an individual array for each single word, 
 *    previously allocating enough memory (len of word + 1)
 *    Split the string into a two dimensional array as drawn below:
 *
 * 				     				   ------  char_index =  0   1   2   3
 *	 		   			  w-index = 0 | ptr1 | ----------> | o | n | e | \0|
 *				      				  |------|      
 * 						  w_index = 1 | ptr2 | ----------> | t | w | o | \0|
 * str = "one,two,three" ---> 	      |------|
 * c = ','				  w_index = 2 | ptr3 | ----------> | t | h | r | e | e | \0|
 *				      				  |------|
 *						  w_index = 3 | NULL |
 *				      				   ------
 *	 Before filling the array , we must allocate enough memory for each array of
 *	 single word (word_len + 1). If allocation fails, we call ft_free. 
*/

#include <stdlib.h>

int	ft_word_counter(const char *str, char c)
{
	int	i;
	int	num_words;

	i = 0;
	num_words = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i] != '\0')
			num_words++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (num_words);
}

static int	ft_word_len(char const *str, char c, int i)
{
	int	len;

	len = 0;
	while (str[i] == c && str[i] != '\0')
		i++;
	while (str[i] != c && str[i] != '\0')
	{
		len++;
		i++;
	}
	return (len);
}

static char	**ft_free(char **str_arr, int w_index)
{
	while (w_index >= 0)
	{	
		free(str_arr[w_index]);
		w_index--;
	}
	free(str_arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str_arr;
	size_t	i;
	int		w_index;
	int		char_index;

	i = 0;
	w_index = -1;
	char_index = 0;
	str_arr = (char **)malloc((ft_word_counter(s, c) + 1) * sizeof(char *));
	if (!str_arr)
		return (NULL);
	while (++w_index < ft_word_counter(s, c))
	{
		char_index = 0;
		str_arr[w_index] = malloc((ft_word_len(s, c, i) + 1) * sizeof(char));
		if (!str_arr[w_index])
			return (ft_free(str_arr, w_index - 1));
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
			str_arr[w_index][char_index++] = s[i++];
		str_arr[w_index][char_index] = '\0';
	}
	str_arr[w_index++] = NULL;
	return (str_arr);
}