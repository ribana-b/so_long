/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 22:23:11 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/26 20:51:10 by ribana-b         ###   ########.com      */
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
	else if (status == INVALID_MAP_EXTENSION)
		ft_fprintf(STDERR, "Invalid map extension, it must be .ber\n");
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

void	ft_exit(t_info *info, int status)
{
	char	*temp;

	temp = get_next_line(info->parser.fd);
	while (temp)
	{
		ft_free(&temp, 1);
		temp = get_next_line(info->parser.fd);
	}
	handle_error(info, status);
	ft_free(&info->map.map, 2);
	ft_free(&info->parser.line, 1);
	ft_close(info);
	exit(status);
}
