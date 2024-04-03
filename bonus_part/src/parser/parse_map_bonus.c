/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:42:55 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 06:37:39 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	nothing_missing(char **map)
{
	int	index;
	int	index2;

	index = -1;
	while (map[++index])
	{
		index2 = -1;
		while (map[index][++index2])
		{
			if (map[index][index2] == PLAYER
				|| map[index][index2] == COLLECTIBLE
				|| map[index][index2] == EXIT)
				return (KO);
		}
	}
	return (OK);
}

static void	flood_fill(t_info *info, char ***map, int x, int y)
{
	if ((*map)[x][y] != WALL && (*map)[x][y] != FILL && (*map)[x][y] != ENEMY)
	{
		(*map)[x][y] = FILL;
		flood_fill(info, map, x - 1, y);
		flood_fill(info, map, x, y - 1);
		flood_fill(info, map, x + 1, y);
		flood_fill(info, map, x, y + 1);
	}
}

static void	last_parse(t_info *info)
{
	int	index;
	int	temp_fd;

	index = -1;
	while (info->map.map[info->map.height - 1][++index]
		&& info->map.map[info->map.height - 1][index + 1])
		if (info->map.map[info->map.height - 1][index] != WALL)
			ft_exit(info, INVALID_NOT_CLOSED);
	if (info->map.has_enemy)
	{
		temp_fd = open(info->path.enemy, O_RDONLY);
		if (temp_fd < 0)
			ft_exit(info, INVALID_TEXTURE);
		close(temp_fd);
	}
}

void	parse_map(t_info *info)
{
	char	**map;
	int		index;

	last_parse(info);
	map = malloc((info->map.height + 1) * sizeof(*info->map.map));
	if (!map)
		ft_exit(info, RIP_MALLOC);
	map[info->map.height] = NULL;
	index = -1;
	while (info->map.map[++index])
	{
		map[index] = ft_strdup(info->map.map[index]);
		if (!map[index])
		{
			ft_free(&map, 2);
			ft_exit(info, RIP_MALLOC);
		}
	}
	flood_fill(info, &map, info->player.x, info->player.y);
	if (nothing_missing(map) != OK)
	{
		ft_free(&map, 2);
		ft_exit(info, INVALID_MAP_UNREACHABLE);
	}
	ft_free(&map, 2);
}
