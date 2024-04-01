/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:21:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 14:42:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_floor(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.floor[RED]);
	info->sprite.floor[RED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(info->path.floor[YELLOW]);
	info->sprite.floor[YELLOW] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(info->path.floor[PURPLE]);
	info->sprite.floor[PURPLE] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(info->path.floor[GREEN]);
	info->sprite.floor[GREEN] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(info->path.floor[CYAN]);
	info->sprite.floor[CYAN] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_wall(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.wall);
	info->sprite.wall = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_player(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.player);
	info->sprite.player = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
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
