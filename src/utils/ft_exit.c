/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:23:11 by ribana-b          #+#    #+# Malaga      */
<<<<<<< HEAD
/*   Updated: 2024/04/03 05:23:09 by ribana-b         ###   ########.com      */
=======
/*   Updated: 2024/04/03 05:05:39 by ribana-b         ###   ########.com      */
>>>>>>> 256406011385e46fe7301e9553a14f0ca40e2031
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	t_color		color;
	t_direction	direction;
	t_status	status;

	color = RED - 1;
	while (++color < COLOR)
		ft_free(&info->path.floor[color], 1);
	direction = UP - 1;
<<<<<<< HEAD
	while (++direction < DIRECTION)
=======
	while (++direction < COLOR)
>>>>>>> 256406011385e46fe7301e9553a14f0ca40e2031
		ft_free(&info->path.player[direction], 1);
	status = CLOSED - 1;
	while (++status < STATUS)
		ft_free(&info->path.exit_map[status], 1);
	ft_free(&info->map.map, 2);
	ft_free(&info->parser.line, 1);
	ft_free(&info->collectible, 1);
	ft_free(&info->path.wall, 1);
	ft_free(&info->path.collectible, 1);
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
