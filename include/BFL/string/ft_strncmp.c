/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:16 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:47:16 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

int	ft_strncmp(const char *str, const char *str2, size_t bytes)
{
	int	index;

	if (!str || !str2)
		return (-1);
	index = 0;
	while (bytes-- && (str[index] || str2[index]))
	{
		if (str[index] != str2[index])
			return ((unsigned char)str[index] - (unsigned char)str2[index]);
		index++;
	}
	return (0);
}
