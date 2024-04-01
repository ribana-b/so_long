/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:53:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 04:51:54 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_player(t_info *info)
{
	mlx_delete_image(info->mlx, info->sprite.player);
	load_player(info);
	mlx_image_to_window(info->mlx, info->sprite.player,
		info->player.y * RESIZE, info->player.x * RESIZE);
}

static void	draw_map(t_info *info)
{
	int		index[2];

	index[0] = -1;
	reload_textures(info);
	while (++index[0] < info->map.width)
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
}

static void	draw_collectibles(t_info *info)
{
	int	index;

	index = -1;
	while (++index < info->parser.amount[T_COLLECTIBLE])
	{
		if (!info->collectible[index].is_collected)
			mlx_image_to_window(info->mlx, info->sprite.collectible,
				info->collectible[index].y * RESIZE,
				info->collectible[index].x * RESIZE);
	}
}

static void	draw_exit_map(t_info *info)
{
	mlx_delete_image(info->mlx, info->sprite.exit_map[OPENED]);
	mlx_delete_image(info->mlx, info->sprite.exit_map[CLOSED]);
	load_exit_map(info);
	if (info->exit_map.is_opened)
	{
		mlx_image_to_window(info->mlx, info->sprite.exit_map[OPENED],
			info->exit_map.y * RESIZE, info->exit_map.x * RESIZE);
	}
	else
	{
		mlx_image_to_window(info->mlx, info->sprite.exit_map[CLOSED],
			info->exit_map.y * RESIZE, info->exit_map.x * RESIZE);
	}
}

void	draw_textures(void *data)
{
	static int	buffer;
	t_info		*info;

	info = data;
	if (buffer % info->refresh_rate == 0)
	{
		draw_map(info);
		draw_collectibles(info);
		draw_exit_map(info);
		draw_player(info);
	}
	if (info->force_redraw)
	{
		draw_exit_map(info);
		draw_player(info);
		info->force_redraw = FALSE;
	}
	if (++buffer >= 600)
		buffer = 0;
}
