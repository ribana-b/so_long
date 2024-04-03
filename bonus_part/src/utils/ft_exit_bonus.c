/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:23:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 02:50:34 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	handle_error_2(t_info *info, int status)
{
	if (status == INVALID_COLLECTIBLE_AMOUNT)
		ft_fprintf(STDERR,
			"Invalid map, it must have at least 1 collectible, found %d\n",
			info->parser.amount[T_COLLECTIBLE]);
	else if (status == INVALID_EXIT_AMOUNT)
		ft_fprintf(STDERR, "Invalid map, it must have 1 exit, found %d\n",
			info->parser.amount[T_EXIT]);
	else if (status == INVALID_MAP_UNREACHABLE)
		ft_fprintf(STDERR, "Invalid map, the player is not able to collect\
 every collectible and exit successfully\n");
	else if (status == INVALID_TEXTURE)
		ft_fprintf(STDERR, "Invalid texture, I can't open it\n");
}

static void	handle_error(t_info *info, int status)
{
	ft_fprintf(STDERR, ERROR_LOG);
	if (status == KO)
		ft_fprintf(STDERR, "Running the program\n");
	else if (status == RIP_MALLOC)
		ft_fprintf(STDERR, "Allocating memory\n");
	else if (status == INVALID_FD)
		ft_fprintf(STDERR, "Couldn't open %s\n", info->map_name);
	else if (status == INVALID_MAP)
		ft_fprintf(STDERR, "Invalid map\n");
	else if (status == INVALID_SIZE)
		ft_fprintf(STDERR, "Invalid map size, it must be rectangular\n");
	else if (status == INVALID_MAP_NAME)
		ft_fprintf(STDERR, "Invalid map name, it must be .ber\n");
	else if (status == INVALID_MAP_FILE)
		ft_fprintf(STDERR, "Invalid map, it must be a .ber file\n");
	else if (status == INVALID_CHARACTER)
		ft_fprintf(STDERR, "Found invalid character '%c'\n",
			info->invalid_character);
	else if (status == INVALID_NOT_CLOSED)
		ft_fprintf(STDERR, "Invalid map, it must be enclosed by walls\n");
	else if (status == INVALID_PLAYER_AMOUNT)
		ft_fprintf(STDERR, "Invalid map, it must have 1 player, found %d\n",
			info->parser.amount[T_PLAYER]);
	handle_error_2(info, status);
}

static void	free_resources(t_info *info)
{
	t_color	color;

	color = RED - 1;
	ft_free(&info->map.map, 2);
	ft_free(&info->parser.line, 1);
	ft_free(&info->collectible, 1);
	while (++color < COLOR)
		ft_free(&info->path.floor[color], 1);
	ft_free(&info->path.wall, 1);
	ft_free(&info->path.player, 1);
	ft_free(&info->path.collectible, 1);
	ft_free(&info->path.exit_map[OPENED], 1);
	ft_free(&info->path.exit_map[CLOSED], 1);
	ft_free(&info->path.relative_path, 1);
}

void	ft_exit(t_info *info, int status)
{
	char	*temp;

	temp = get_next_line(info->parser.fd);
	while (temp)
	{
		ft_free(&temp, 1);
		temp = get_next_line(info->parser.fd);
	}
	if (status != OK)
		handle_error(info, status);
	free_resources(info);
	ft_close(info);
	exit(status);
}
