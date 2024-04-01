/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:57:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 01:51:27 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	can_move_up(t_info *info)
{
	if (info->map.map[info->player.x - 1][info->player.y] != WALL)
	{
		mlx_image_to_window(info->mlx, info->sprite.player,
			(info->player.y) * RESIZE, (info->player.x - 1) * RESIZE);
		mlx_image_to_window(info->mlx,
			info->sprite.floor[ft_random(info) % COLOR],
			(info->player.y) * RESIZE, (info->player.x) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_down(t_info *info)
{
	if (info->map.map[info->player.x + 1][info->player.y] != WALL)
	{
		mlx_image_to_window(info->mlx, info->sprite.player,
			(info->player.y) * RESIZE, (info->player.x + 1) * RESIZE);
		mlx_image_to_window(info->mlx,
			info->sprite.floor[ft_random(info) % COLOR],
			(info->player.y) * RESIZE, (info->player.x) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_left(t_info *info)
{
	if (info->map.map[info->player.x][info->player.y - 1] != WALL)
	{
		mlx_image_to_window(info->mlx, info->sprite.player,
			(info->player.y - 1) * RESIZE, (info->player.x) * RESIZE);
		mlx_image_to_window(info->mlx,
			info->sprite.floor[ft_random(info) % COLOR],
			(info->player.y) * RESIZE, (info->player.x) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_right(t_info *info)
{
	if (info->map.map[info->player.x][info->player.y + 1] != WALL)
	{
		mlx_image_to_window(info->mlx, info->sprite.player,
			(info->player.y + 1) * RESIZE, (info->player.x) * RESIZE);
		mlx_image_to_window(info->mlx,
			info->sprite.floor[ft_random(info) % COLOR],
			(info->player.y) * RESIZE, (info->player.x) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}
