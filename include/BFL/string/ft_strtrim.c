/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/24 14:53:40 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

char	*ft_strtrim(const char *str, const char *str2)
{
	size_t	start;
	size_t	end;

	if (!str || !str2)
		return (NULL);
	if (!(*str))
		return (ft_calloc(1, 1));
	start = 0;
	while (ft_strchr(str2, str[start]))
		start++;
	end = ft_strlen(str);
	while (ft_strchr(str2, str[end]))
		end--;
	return (ft_substr(str, start, end - start + 1));
}
