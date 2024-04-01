/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 14:02:59 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/01 14:57:12 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_exit_map_sprite(t_info *info)
{
	info->path.exit_map[OPENED] = ft_strjoin(info->path.relative_path,
			PATH"exit_map_opened.png");
	info->path.exit_map[CLOSED] = ft_strjoin(info->path.relative_path,
			PATH"exit_map_closed.png");
	if (!info->path.exit_map[OPENED] || !info->path.exit_map[CLOSED])
		ft_exit(info, RIP_MALLOC);
}

static void	get_floor_sprite(t_info *info)
{
	t_color	color;

	color = RED - 1;
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"floor.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"floor2.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"floor3.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"floor4.png");
	info->path.floor[++color] = ft_strjoin(info->path.relative_path,
			PATH"floor5.png");
	color = RED - 1;
	while (++color < COLOR)
		if (!info->path.floor[color])
			ft_exit(info, RIP_MALLOC);
}

void	get_sprites_path(t_info *info, char *map_name)
{
	info->path.relative_path = ft_substr(map_name, 0,
			ft_strlen(map_name) - ft_strlen(ft_strnstr(map_name, "maps",
					ft_strlen(map_name))));
	if (!info->path.relative_path)
		ft_exit(info, RIP_MALLOC);
	get_floor_sprite(info);
	get_exit_map_sprite(info);
	info->path.wall = ft_strjoin(info->path.relative_path, PATH"wall.png");
	info->path.player = ft_strjoin(info->path.relative_path, PATH"player.png");
	info->path.collectible = ft_strjoin(info->path.relative_path,
			PATH"collectible.png");
	if (!info->path.wall || !info->path.player || !info->path.collectible)
		ft_exit(info, RIP_MALLOC);
}
