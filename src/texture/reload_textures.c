/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:49:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 04:50:08 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reload_textures(t_info *info)
{
	t_color	color;

	mlx_delete_image(info->mlx, info->sprite.player);
	mlx_delete_image(info->mlx, info->sprite.wall);
	mlx_delete_image(info->mlx, info->sprite.collectible);
	mlx_delete_image(info->mlx, info->sprite.exit_map[OPENED]);
	mlx_delete_image(info->mlx, info->sprite.exit_map[CLOSED]);
	color = RED;
	while (color < COLOR)
	{
		mlx_delete_image(info->mlx, info->sprite.floor[color]);
		++color;
	}
	load_textures(info);
}
