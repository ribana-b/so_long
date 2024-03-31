/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 22:55:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/31 23:19:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

void	*ft_realloc(void *ptr, size_t current_size, size_t new_size,
			size_t element_size)
{
	char	*temp;

	if (!new_size || !element_size)
		return (NULL);
	temp = malloc((new_size + 1) * element_size);
	if (!temp)
		return (ft_free(&ptr, 1));
	ft_memcpy(temp, ptr, current_size * element_size);
	ft_free(&ptr, 1);
	ptr = temp;
	return (ptr);
}
