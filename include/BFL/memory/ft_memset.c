/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:49 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:46:49 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	ft_memset(void *ptr, int character, size_t bytes)
{
	char	*temp;

	if (!ptr)
		return ;
	temp = (char *)ptr;
	while (bytes-- > 0)
		temp[bytes] = character;
	return ;
}
