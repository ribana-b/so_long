/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 07:17:41 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 00:49:42 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

unsigned long	ft_random(t_info *info)
{
	if (SEED > 0 && info->random_number >= SEED)
		info->random_number %= SEED;
	return (++info->random_number + mlx_get_time());
}
