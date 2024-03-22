/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:47:18 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_strnstr(const char *str, const char *str2, size_t bytes)
{
	size_t	length;
	char	*temp;

	length = ft_strlen(str2);
	if (!str || !str2 || (!(*str) && *str2))
		return (NULL);
	if (!(*str2))
		return ((char *)str);
	temp = (char *)str;
	while (bytes >= length && bytes--)
	{
		if (ft_strncmp(temp, str2, length) == 0)
			return (temp);
		temp++;
	}
	return (NULL);
}
