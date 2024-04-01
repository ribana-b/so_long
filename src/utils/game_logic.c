/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 02:46:56 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 04:53:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	is_finished(t_info *info)
{
	if (info->map.map[info->player.x][info->player.y] == EXIT
		&& info->exit_map.is_opened)
	{
		handle_close_window(info->mlx);
		ft_fprintf(STDOUT, INFO_LOG"Player exited succesfully\n");
	}
}

void	game_logic(void *data)
{
	t_info			*info;
	static t_bool	is_draw;

	info = data;
	is_draw = TRUE;
	if (info->player.collected == info->parser.amount[T_COLLECTIBLE] && is_draw)
	{
		draw_textures(info);
		is_draw = FALSE;
	}
	is_finished(info);
}
