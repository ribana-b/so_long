/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:57:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/02 15:43:18 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_bool	can_move_up(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	info->player.current_direction = UP;
	if (info->map.map[info->player.x - 1][info->player.y] != WALL)
	{
		while (++direction < DIRECTION)
			mlx_delete_image(info->mlx, info->sprite.player[direction]);
		load_player(info);
		mlx_image_to_window(info->mlx, info->sprite.player[UP],
			info->player.y * RESIZE, (info->player.x - 1) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_down(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	info->player.current_direction = DOWN;
	if (info->map.map[info->player.x + 1][info->player.y] != WALL)
	{
		while (++direction < DIRECTION)
			mlx_delete_image(info->mlx, info->sprite.player[direction]);
		load_player(info);
		mlx_image_to_window(info->mlx, info->sprite.player[DOWN],
			info->player.y * RESIZE, (info->player.x + 1) * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_left(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	info->player.current_direction = LEFT;
	if (info->map.map[info->player.x][info->player.y - 1] != WALL)
	{
		while (++direction < DIRECTION)
			mlx_delete_image(info->mlx, info->sprite.player[direction]);
		load_player(info);
		mlx_image_to_window(info->mlx, info->sprite.player[LEFT],
			(info->player.y - 1) * RESIZE, info->player.x * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}

t_bool	can_move_right(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	info->player.current_direction = RIGHT;
	if (info->map.map[info->player.x][info->player.y + 1] != WALL)
	{
		while (++direction < DIRECTION)
			mlx_delete_image(info->mlx, info->sprite.player[direction]);
		load_player(info);
		mlx_image_to_window(info->mlx, info->sprite.player[RIGHT],
			(info->player.y + 1) * RESIZE, info->player.x * RESIZE);
		++info->step_counter;
		ft_fprintf(STDOUT, INFO_LOG"Counter: %u\n", info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}
