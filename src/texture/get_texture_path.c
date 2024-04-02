/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:02:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/02 18:53:32 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_exit_map_texture(t_info *info)
{
	info->path.exit_map[OPENED] = ft_strjoin(info->path.relative_path,
			PATH"exit_map_opened.png");
	info->path.exit_map[CLOSED] = ft_strjoin(info->path.relative_path,
			PATH"exit_map_closed.png");
	if (!info->path.exit_map[OPENED] || !info->path.exit_map[CLOSED])
		ft_exit(info, RIP_MALLOC);
}

static void	get_floor_texture(t_info *info)
{
	t_color	color;

	color = RED - 1;
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"red_floor.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"yellow_floor.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"purple_floor.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"green_floor.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"cyan_floor.png");
	color = RED - 1;
	while (++color < COLOR)
		if (!info->path.floor[color])
			ft_exit(info, RIP_MALLOC);
}

static void	get_player_texture(t_info *info)
{
	t_direction	direction;

	direction = UP - 1;
	info->path.player[++direction] = ft_strjoin(info->path.relative_path,
			PATH"chopper_up.png");
	info->path.player[++direction] = ft_strjoin(info->path.relative_path,
			PATH"chopper_left.png");
	info->path.player[++direction] = ft_strjoin(info->path.relative_path,
			PATH"chopper_down.png");
	info->path.player[++direction] = ft_strjoin(info->path.relative_path,
			PATH"chopper_right.png");
	direction = UP - 1;
	while (++direction < 4)
		if (!info->path.player[direction])
			ft_exit(info, RIP_MALLOC);
}

void	get_texture_path(t_info *info, char *map_name)
{
	info->path.relative_path = ft_substr(map_name, 0,
			ft_strlen(map_name) - ft_strlen(ft_strnstr(map_name, "maps",
					ft_strlen(map_name))));
	if (!info->path.relative_path)
		ft_exit(info, RIP_MALLOC);
	get_floor_texture(info);
	get_player_texture(info);
	get_exit_map_texture(info);
	info->path.wall = ft_strjoin(info->path.relative_path,
			PATH"speaker_wall.png");
	info->path.collectible = ft_strjoin(info->path.relative_path,
			PATH"collectible.png");
	if (!info->path.wall || !info->path.collectible)
		ft_exit(info, RIP_MALLOC);
}
