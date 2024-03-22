/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:37 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:46:37 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	*ft_calloc(size_t bytes, size_t size_type)
{
	void	*ptr;

	ptr = malloc(bytes * size_type);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, bytes * size_type);
	return (ptr);
}
