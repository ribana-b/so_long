/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 05:53:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 05:21:30 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	draw_player(t_info *info)
{
	reload_player(info);
	mlx_image_to_window(info->mlx,
		info->sprite.player[info->player.current_direction],
		info->player.y * RESIZE, info->player.x * RESIZE);
}

static void	draw_map(t_info *info)
{
	int		index[2];

	index[0] = -1;
	reload_map(info);
	while (++index[0] < info->map.width)
	{
		index[1] = -1;
		while (++index[1] < info->map.height)
		{
			mlx_image_to_window(info->mlx,
				info->sprite.floor[ft_random(info) % COLOR],
				index[0] * RESIZE, index[1] * RESIZE);
			if (info->map.map[index[1]][index[0]] == WALL)
				mlx_image_to_window(info->mlx, info->sprite.wall,
					index[0] * RESIZE, index[1] * RESIZE);
			if (info->map.has_enemy
				&& info->map.map[index[1]][index[0]] == ENEMY)
				mlx_image_to_window(info->mlx, info->sprite.enemy,
					index[0] * RESIZE, index[1] * RESIZE);
		}
	}
}

static void	draw_collectibles(t_info *info)
{
	int	index;

	index = -1;
	reload_collectible(info);
	if (info->player.collected == info->parser.amount[T_COLLECTIBLE])
		return ;
	while (++index < info->parser.amount[T_COLLECTIBLE])
	{
		if (!info->collectible[index].is_collected)
		{
			mlx_image_to_window(info->mlx, info->sprite.collectible,
				info->collectible[index].y * RESIZE,
				info->collectible[index].x * RESIZE);
		}
	}
}

static void	draw_exit_map(t_info *info)
{
	reload_exit_map(info);
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
	if ((info->refresh_rate >= MIN_REFRESH_RATE
			&& buffer % info->refresh_rate == 0)
		|| (info->refresh_rate < MIN_REFRESH_RATE && !buffer))
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
		buffer = 1;
	if (info->step_counter)
		print_step_counter(info);
}
