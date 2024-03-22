/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:36 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:46:36 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	ft_bzero(void *ptr, size_t bytes)
{
	if (!ptr)
		return ;
	ft_memset(ptr, '\0', bytes);
	return ;
}
