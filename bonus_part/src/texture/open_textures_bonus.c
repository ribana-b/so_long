/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 15:50:18 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 06:30:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	open_floor_texture(t_info *info, int *temp_fd)
{
	t_color	color;

	color = RED - 1;
	while (++color < COLOR)
	{
		*temp_fd = open(info->path.floor[color], O_RDONLY);
		if (*temp_fd < 0)
			ft_exit(info, INVALID_TEXTURE);
		close(*temp_fd);
	}
}

static void	open_player_texture(t_info *info, int *temp_fd)
{
	t_direction	direction;

	direction = UP - 1;
	while (++direction < DIRECTION)
	{
		*temp_fd = open(info->path.player[direction], O_RDONLY);
		if (*temp_fd < 0)
			ft_exit(info, INVALID_TEXTURE);
		close(*temp_fd);
	}
}

static void	open_exit_map_texture(t_info *info, int *temp_fd)
{
	t_status	status;

	status = CLOSED - 1;
	while (++status < STATUS)
	{
		*temp_fd = open(info->path.exit_map[status], O_RDONLY);
		if (*temp_fd < 0)
			ft_exit(info, INVALID_TEXTURE);
		close(*temp_fd);
	}
}

void	open_textures(t_info *info)
{
	int	temp_fd;

	temp_fd = open(info->path.collectible, O_RDONLY);
	if (temp_fd < 0)
		ft_exit(info, INVALID_TEXTURE);
	close(temp_fd);
	temp_fd = open(info->path.wall, O_RDONLY);
	if (temp_fd < 0)
		ft_exit(info, INVALID_TEXTURE);
	open_floor_texture(info, &temp_fd);
	open_player_texture(info, &temp_fd);
	open_exit_map_texture(info, &temp_fd);
}
