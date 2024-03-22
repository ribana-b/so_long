/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:58:47 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parse_args(char *argv)
{
	char	**split;

	split = ft_split(argv, ' ');
	if (!split)
		return (RIP_MALLOC);
	if (ft_splitlen(split) != 1)
	{
		ft_free(&split, 2);
		return (INVALID_ARGS);
	}
	if (ft_strncmp(split[0] + ft_strlen(split[0]) - 4, ".ber", 4) != 0)
	{
		ft_free(&split, 2);
		return (INVALID_MAP);
	}
	ft_free(&split, 2);
	return (OK);
}

int	so_long(char *map_name)
{
	mlx_t	*mlx;

	(void)map_name;
	mlx = mlx_init(WIDTH, HEIGHT, "so_long", TRUE);
	if (!mlx)
	{
		ft_fprintf(STDERR, "%s %s\n", ERROR_LOG, mlx_strerror(mlx_errno));
		return (KO);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (OK);
}

int	main(int argc, char **argv)
{
	int	status;

	if (argc != 2)
	{
		ft_fprintf(STDERR, "Usage: %s map.ber\n", argv[0]);
		return (INVALID_ARGC);
	}
	if (parse_args(argv[1]) != OK)
	{
		ft_fprintf(STDERR, "%s Invalid map\n", ERROR_LOG);
		return (INVALID_MAP);
	}
	status = so_long(argv[1]);
	return (status);
}
