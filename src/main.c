/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:55:43 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 16:58:28 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	mlx_t	*mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "so_long", TRUE);
	if (!mlx)
	{
		ft_fprintf(2, "%s", mlx_strerror(mlx_errno));
		return (KO);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (OK);
}
