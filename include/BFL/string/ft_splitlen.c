/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:47:00 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:50:49 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	ft_splitlen(char **split)
{
	size_t	counter;

	if (!split)
		return (0);
	counter = 0;
	while (split[counter])
		counter++;
	return (counter);
}
