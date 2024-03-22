/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:22 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:47:22 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

char	*ft_substr(const char *str, size_t start, size_t bytes)
{
	char	*new_str;

	if (!str)
		return (NULL);
	if ((bytes + start) > ft_strlen(str))
		bytes = ft_strlen(str) - start;
	if (start >= ft_strlen(str))
		return (ft_calloc(1, 1));
	new_str = (char *)malloc((bytes + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[bytes] = '\0';
	while (bytes-- > 0)
		new_str[bytes] = str[start + bytes];
	return (new_str);
}
