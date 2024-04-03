/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reload_textures_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 04:49:45 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 05:26:16 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	reload_player(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	while (++direction < DIRECTION)
		mlx_delete_image(info->mlx, info->sprite.player[direction]);
	load_player(info);
}

void	reload_map(t_info *info)
{
	t_color		color;

	color = RED - 1;
	while (++color < COLOR)
		mlx_delete_image(info->mlx, info->sprite.floor[color]);
	load_floor(info);
	mlx_delete_image(info->mlx, info->sprite.wall);
	load_wall(info);
	if (info->map.has_enemy)
	{
		mlx_delete_image(info->mlx, info->sprite.enemy);
		load_enemy(info);
	}
}

void	reload_collectible(t_info *info)
{
	mlx_delete_image(info->mlx, info->sprite.collectible);
	load_collectible(info);
}

void	reload_exit_map(t_info *info)
{
	mlx_delete_image(info->mlx, info->sprite.exit_map[OPENED]);
	mlx_delete_image(info->mlx, info->sprite.exit_map[CLOSED]);
	load_exit_map(info);
}

void	reload_textures(t_info *info)
{
	t_color		color;
	t_direction	direction;

	mlx_delete_image(info->mlx, info->sprite.wall);
	mlx_delete_image(info->mlx, info->sprite.collectible);
	mlx_delete_image(info->mlx, info->sprite.exit_map[OPENED]);
	mlx_delete_image(info->mlx, info->sprite.exit_map[CLOSED]);
	color = RED - 1;
	while (++color < COLOR)
		mlx_delete_image(info->mlx, info->sprite.floor[color]);
	direction = UP - 1;
	while (++direction < DIRECTION)
		mlx_delete_image(info->mlx, info->sprite.player[direction]);
	load_textures(info);
}
