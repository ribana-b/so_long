/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:21:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 02:22:28 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_floor(t_info *info)
{
	t_color	color;

	color = RED - 1;
	while (++color < COLOR)
	{
		info->sprite.texture = mlx_load_png(info->path.floor[color]);
		info->sprite.floor[color] = mlx_texture_to_image(info->mlx,
				info->sprite.texture);
		mlx_delete_texture(info->sprite.texture);
	}
}

void	load_wall(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.wall);
	info->sprite.wall = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_player(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	while (++direction < DIRECTION)
	{
		info->sprite.texture = mlx_load_png(info->path.player[direction]);
		info->sprite.player[direction] = mlx_texture_to_image(info->mlx,
				info->sprite.texture);
		mlx_delete_texture(info->sprite.texture);
	}
}

void	load_collectible(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.collectible);
	info->sprite.collectible = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_exit_map(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.exit_map[OPENED]);
	info->sprite.exit_map[OPENED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(info->path.exit_map[CLOSED]);
	info->sprite.exit_map[CLOSED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}
