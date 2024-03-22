/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:46:59 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

static char	**free_split(char ***split)
{
	size_t	index;

	index = 0;
	while ((*split)[index] != NULL)
	{
		free((*split)[index]);
		(*split)[index++] = NULL;
	}
	free(*split);
	*split = NULL;
	return (NULL);
}

static size_t	count_word(const char *str, char delimit)
{
	size_t	counter;
	size_t	index;

	if (!str)
		return (0);
	counter = 0;
	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] == delimit)
			index++;
		else
		{
			counter++;
			while (str[index] != delimit && str[index] != '\0')
				index++;
		}
	}
	return (counter);
}

static char	*get_word(const char *str, char delimit, size_t *index)
{
	char	*word;
	size_t	index2;

	index2 = 0;
	while (str[*index + index2] != '\0' && str[*index + index2] != delimit)
		index2++;
	word = (char *)malloc((index2 + 1) * sizeof(char));
	if (!word)
		return (NULL);
	index2 = 0;
	while (str[*index] != '\0' && str[*index] != delimit)
	{
		word[index2] = str[*index];
		index2++;
		(*index)++;
	}
	word[index2] = '\0';
	return (word);
}

char	**ft_split(const char *str, char delimit)
{
	char	**split;
	size_t	split_index;
	size_t	str_index;

	if (!str)
		return (NULL);
	split = (char **)malloc((count_word(str, delimit) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split_index = 0;
	str_index = 0;
	while (str[str_index] != '\0')
	{
		if (str[str_index] == delimit)
			str_index++;
		else
		{
			split[split_index] = get_word(str, delimit, &str_index);
			if (!split[split_index])
				return (free_split(&split));
			split_index++;
		}
	}
	split[split_index] = NULL;
	return (split);
}
