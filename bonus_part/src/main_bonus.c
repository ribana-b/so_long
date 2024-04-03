/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 05:32:55 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_textures(t_info *info)
{
	load_wall(info);
	load_floor(info);
	load_player(info);
	if (info->map.has_enemy)
		load_enemy(info);
	load_collectible(info);
	load_exit_map(info);
}

static void	so_long(t_info *info)
{
	info->mlx = mlx_init(info->map.width * RESIZE, info->map.height * RESIZE,
			"so_long", FALSE);
	if (!info->mlx)
		ft_exit(info, KO);
	load_textures(info);
	draw_textures(info);
	mlx_close_hook(info->mlx, handle_close_window, info->mlx);
	mlx_key_hook(info->mlx, handle_key_input, info);
	if (info->refresh_rate >= MIN_REFRESH_RATE)
		mlx_loop_hook(info->mlx, draw_textures, info);
	mlx_loop_hook(info->mlx, game_logic, info);
	mlx_loop(info->mlx);
	mlx_terminate(info->mlx);
}

static void	initialise_info(t_info *info, char *map_name)
{
	info->map = (t_map){0};
	info->player = (t_player){0};
	info->player.current_direction = DOWN;
	info->collectible = NULL;
	info->exit_map = (t_exit_map){0};
	info->parser = (t_parser){0};
	info->parser.fd = -1;
	info->map_name = map_name;
	info->mlx = NULL;
	info->step_counter = 0;
	info->random_number = 0;
	info->refresh_rate = 60;
	info->force_redraw = FALSE;
	info->path = (t_path){0};
	get_texture_path(info, map_name);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (argc != 2 || (argc == 2 && ft_strlen(argv[1]) < 5))
	{
		ft_fprintf(STDERR, ERROR_LOG"Usage: %s <map_name>\n", argv[0]);
		return (INVALID_ARGC);
	}
	initialise_info(&info, argv[1]);
	open_textures(&info);
	parse_name(&info);
	parse_line(&info);
	fill_map(&info);
	parse_map(&info);
	so_long(&info);
	ft_exit(&info, OK);
}
