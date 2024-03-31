/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:46 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/24 14:53:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*ft_memcpy(void *str, const void *str2, size_t bytes)
{
	char	*temp;
	char	*temp2;

	if (!str || !str2)
		return (NULL);
	temp = (char *)str;
	temp2 = (char *)str2;
	while (bytes--)
		temp[bytes] = temp2[bytes];
	return (str);
}
