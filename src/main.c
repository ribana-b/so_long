/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 07:31:56 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_info *info)
{
	load_floor(info);
	load_wall(info);
	load_player(info);
	load_collectible(info);
	load_exit_map(info);
}

static void	so_long(t_info *info)
{
	info->mlx = mlx_init(WIDTH, HEIGHT, "so_long", TRUE);
	if (!info->mlx)
		ft_exit(info, KO);
	load_textures(info);
	draw_textures(info);
	mlx_close_hook(info->mlx, handle_close_window, info->mlx);
	mlx_key_hook(info->mlx, handle_key_input, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
}

static void	initialise_info(t_info *info, char *map_name)
{
	info->map = (t_map){0};
	info->player.x = 0;
	info->player.y = 0;
	info->collectible = (t_collectible){0};
	info->exit_map = (t_exit_map){0};
	info->parser = (t_parser){0};
	info->parser.fd = -1;
	info->map_name = map_name;
	info->mlx = NULL;
	info->step_counter = 0;
	info->random_number = 25;
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || (argc == 2 && ft_strlen(argv[1]) < 5))
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
