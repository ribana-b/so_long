/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:09:05 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 04:32:22 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_close_window(void *data)
{
	mlx_t	*mlx;

	mlx = data;
	mlx_close_window(mlx);
	ft_fprintf(STDOUT, INFO_LOG"Window closed successfully\n");
}

static void	handle_collection(t_info *info)
{
	int	index;

	index = -1;
	if (info->map.map[info->player.x][info->player.y] == COLLECTIBLE)
	{
		while (++index < info->parser.amount[T_COLLECTIBLE])
		{
			if (!info->collectible[index].is_collected
				&& info->collectible[index].x == info->player.x
				&& info->collectible[index].y == info->player.y)
			{
				++info->player.collected;
				info->collectible[index].is_collected = TRUE;
				mlx_image_to_window(info->mlx,
					info->sprite.floor[ft_random(info) % COLOR],
					info->collectible[index].y * RESIZE,
					info->collectible[index].x * RESIZE);
				break ;
			}
		}
	}
	if (info->player.collected == info->parser.amount[T_COLLECTIBLE])
		info->exit_map.is_opened = TRUE;
}

static void	handle_movement(t_info *info, const char *message)
{
	if (ft_strncmp(message, "up", 2) == 0 && can_move_up(info))
	{
		ft_fprintf(STDOUT, INFO_LOG"Move %s\n", message);
		--info->player.x;
	}
	else if (ft_strncmp(message, "down", 4) == 0 && can_move_down(info))
	{
		ft_fprintf(STDOUT, INFO_LOG"Move %s\n", message);
		++info->player.x;
	}
	else if (ft_strncmp(message, "left", 4) == 0 && can_move_left(info))
	{
		ft_fprintf(STDOUT, INFO_LOG"Move %s\n", message);
		--info->player.y;
	}
	else if (ft_strncmp(message, "right", 4) == 0 && can_move_right(info))
	{
		ft_fprintf(STDOUT, INFO_LOG"Move %s\n", message);
		++info->player.y;
	}
	if (info->map.map[info->player.x][info->player.y] == COLLECTIBLE)
		handle_collection(info);
}

void	handle_key_input(mlx_key_data_t keydata, void *data)
{
	t_info		*info;

	info = data;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_Q)
			handle_close_window(info->mlx);
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W
			|| keydata.key == MLX_KEY_K)
			handle_movement(info, "up");
		if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A
			|| keydata.key == MLX_KEY_H)
			handle_movement(info, "left");
		if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S
			|| keydata.key == MLX_KEY_J)
			handle_movement(info, "down");
		if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D
			|| keydata.key == MLX_KEY_L)
			handle_movement(info, "right");
	}
	info->force_redraw = TRUE;
	draw_textures(info);
}
