/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:48 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:50:35 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*ft_memmove(void *str, const void *str2, size_t bytes)
{
	char	*temp;
	char	*temp2;

	if (!str || !str2)
		return (NULL);
	temp = (char *)str;
	temp2 = (char *)str2;
	if (temp > temp2 || temp < (temp2 + bytes))
		while (bytes--)
			temp[bytes] = temp2[bytes];
	else
		ft_memcpy(str, str2, bytes);
	return (str);
}
