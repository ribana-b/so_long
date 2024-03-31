/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:44 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/24 14:53:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	ft_memcmp(const void *str, const void *str2, size_t bytes)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	if (!str || !str2)
		return (-1);
	temp = (unsigned char *)str;
	temp2 = (unsigned char *)str2;
	while (bytes--)
		if (temp[bytes] != temp2[bytes])
			return (temp[bytes] - temp2[bytes]);
	return (0);
}
