/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:28:01 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:52:06 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* <-- Define Section --> */

# define WIDTH 512
# define HEIGHT 512
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define ERROR_LOG RED"[ERROR]"RESET

/* <-- Libraries Section --> */

# include "BFL.h"
# include "MLX42.h"
# include <stdio.h>

/* Typedef Section */

typedef enum exit_status_2	t_exit_status_2;
typedef struct s_player		t_player;
typedef struct s_map		t_map;

enum exit_status_2
{
	INVALID_ARGS = EXIT_STATUS_LIMIT,
	INVALID_MAP,
};

struct s_player
{
	int	x;
	int	y;
};

struct s_map
{
	int	width;
	int	height;
};

/* Function Section */

#endif // SO_LONG_H
