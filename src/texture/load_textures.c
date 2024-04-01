/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:21:21 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 03:09:18 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_floor(t_info *info)
{
	info->sprite.texture = mlx_load_png(PATH"floor.png");
	info->sprite.floor[RED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(PATH"floor2.png");
	info->sprite.floor[YELLOW] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(PATH"floor3.png");
	info->sprite.floor[PURPLE] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(PATH"floor4.png");
	info->sprite.floor[GREEN] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(PATH"floor5.png");
	info->sprite.floor[CYAN] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_wall(t_info *info)
{
	info->sprite.texture = mlx_load_png(PATH"wall.png");
	info->sprite.wall = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_player(t_info *info)
{
	info->sprite.texture = mlx_load_png(PATH"player.png");
	info->sprite.player = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_collectible(t_info *info)
{
	info->sprite.texture = mlx_load_png(PATH"collectible.png");
	info->sprite.collectible = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}

void	load_exit_map(t_info *info)
{
	info->sprite.texture = mlx_load_png(PATH"exit_map.png");
	info->sprite.exit_map[OPENED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
	info->sprite.texture = mlx_load_png(PATH"floor.png");
	info->sprite.exit_map[CLOSED] = mlx_texture_to_image(info->mlx,
			info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}
