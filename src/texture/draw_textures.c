/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:53:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 08:41:37 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player(t_info *info)
{
	mlx_image_to_window(info->mlx, info->sprite.player,
		info->player.y * RESIZE, info->player.x * RESIZE);
}

void	reload_textures(void *data)
{
	t_color	color;
	t_info	*info;

	info = data;
	mlx_delete_image(info->mlx, info->sprite.player);
	mlx_delete_image(info->mlx, info->sprite.wall);
	mlx_delete_image(info->mlx, info->sprite.collectible);
	mlx_delete_image(info->mlx, info->sprite.exit_map);
	color = RED;
	while (color < COLOR)
	{
		mlx_delete_image(info->mlx, info->sprite.floor[color]);
		++color;
	}
	load_textures(info);
}

void	draw_map(void *data)
{
	int		index[2];
	t_info	*info;

	info = data;
	index[0] = -1;
	reload_textures(info);
	while (++index[0] < info->map.width - 1)
	{
		index[1] = -1;
		while (++index[1] < info->map.height)
		{
			if (info->map.map[index[1]][index[0]] == WALL)
				mlx_image_to_window(info->mlx, info->sprite.wall,
					index[0] * RESIZE, index[1] * RESIZE);
			else
				mlx_image_to_window(info->mlx,
					info->sprite.floor[ft_random(info) % COLOR],
					index[0] * RESIZE, index[1] * RESIZE);
		}
	}
	draw_player(info);
}

void	draw_textures(t_info *info)
{
	draw_map(info);
}
