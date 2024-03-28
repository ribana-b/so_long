/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 19:04:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 04:21:50 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	has_valid_character(t_info *info)
{
	size_t	index;

	index = 0;
	while (info->parser.line[index])
	{
		if (info->parser.line[index] == EXIT)
			++info->parser.amount[T_EXIT];
		else if (info->parser.line[index] == COLLECTIBLE)
			++info->parser.amount[T_COLLECTIBLE];
		else if (info->parser.line[index] == PLAYER)
		{
			info->player.x = info->map.height;
			info->player.y = index;
			++info->parser.amount[T_PLAYER];
		}
		else if (info->parser.line[index] != WALL
			&& info->parser.line[index] != FLOOR
			&& info->parser.line[index] != '\n')
		{
			info->invalid_character = info->parser.line[index];
			ft_exit(info, INVALID_CHARACTER);
		}
		++index;
	}
}

static void	is_valid_line(t_info *info)
{
	static t_bool	is_empty = TRUE;
	static int		length = -1;
	int				index;

	info->map.width = ft_strlen(info->parser.line);
	if (info->map.width)
		is_empty = FALSE;
	if (!is_empty && !info->map.width)
		ft_exit(info, INVALID_MAP);
	if (length != -1 && info->map.width != length)
		ft_exit(info, INVALID_SIZE);
	index = -1;
	if (info->map.height == 0)
	{
		while (info->parser.line[++index] && info->parser.line[index + 1])
			if (info->parser.line[index] != WALL)
				ft_exit(info, INVALID_NOT_CLOSED);
	}
	if (info->parser.line[0] != WALL
		|| info->parser.line[info->map.width - 2] != WALL)
		ft_exit(info, INVALID_NOT_CLOSED);
	length = info->map.width;
}

void	parse_line(t_info *info)
{
	ft_open(info);
	info->parser.line = get_next_line(info->parser.fd);
	if (!info->parser.line)
		ft_exit(info, INVALID_MAP_FILE);
	while (info->parser.line)
	{
		has_valid_character(info);
		is_valid_line(info);
		ft_free(&info->parser.line, 1);
		info->parser.line = get_next_line(info->parser.fd);
		++info->map.height;
	}
	if (info->parser.amount[T_PLAYER] != 1)
		ft_exit(info, INVALID_PLAYER_AMOUNT);
	else if (info->parser.amount[T_EXIT] != 1)
		ft_exit(info, INVALID_EXIT_AMOUNT);
	else if (info->parser.amount[T_COLLECTIBLE] < 1)
		ft_exit(info, INVALID_COLLECTIBLE_AMOUNT);
	ft_close(info);
}
