/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/26 21:50:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	so_long(t_info *info)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", TRUE);
	if (!mlx)
		ft_exit(info, KO);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}

static void	initialise_info(t_info *info, char *map_name)
{
	info->map.map = NULL;
	info->map.width = 0;
	info->map.height = 0;
	info->player.x = 0;
	info->player.y = 0;
	info->collectible.x = 0;
	info->collectible.y = 0;
	info->collectible.is_collected = FALSE;
	info->exit_map.x = 0;
	info->exit_map.y = 0;
	info->exit_map.is_opened = FALSE;
	info->parser.line = NULL;
	info->parser.fd = -1;
	info->parser.is_fd_opened = FALSE;
	info->map_name = map_name;
	info->parser.amount[T_PLAYER] = 0;
	info->parser.amount[T_EXIT] = 0;
	info->parser.amount[T_COLLECTIBLE] = 0;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || (argc == 2 && ft_strlen(argv[1]) == 0))
	{
		ft_fprintf(STDERR, "%s Usage: %s map.ber\n", ERROR_LOG, argv[0]);
		return (INVALID_ARGC);
	}
	initialise_info(&info, argv[1]);
	parse_name(&info);
	parse_line(&info);
	fill_map(&info);
	parse_map(&info);
	so_long(&info);
	ft_free(&info.map.map, 2);
	return (OK);
}
