/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 08:57:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 05:45:09 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_step_counter(t_info *info)
{
	char			*number;
	char			*text;
	static t_bool	drawn;

	if (drawn)
		mlx_delete_image(info->mlx, info->sprite.step_counter_text);
	number = ft_itoa(info->step_counter);
	if (!number)
	{
		handle_close_window(info->mlx);
		ft_exit(info, RIP_MALLOC);
	}
	text = ft_strjoin("Step counter: ", number);
	ft_free(&number, 1);
	if (!text)
		ft_exit(info, RIP_MALLOC);
	info->sprite.step_counter_text = mlx_put_string(info->mlx, text, 0, 0);
	mlx_image_to_window(info->mlx, info->sprite.step_counter_text, 0, 0);
	ft_free(&text, 1);
	drawn = TRUE;
}

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
		ft_fprintf(STDOUT, INFO_LOG"Step counter: %u | Move up\n",
			info->step_counter);
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
		ft_fprintf(STDOUT, INFO_LOG"Step counter: %u | Move down\n",
			info->step_counter);
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
		ft_fprintf(STDOUT, INFO_LOG"Step counter: %u | Move left\n",
			info->step_counter);
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
		ft_fprintf(STDOUT, INFO_LOG"Step counter: %u | Move right\n",
			info->step_counter);
		return (TRUE);
	}
	return (FALSE);
}
