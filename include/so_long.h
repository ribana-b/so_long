/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:28:01 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/23 12:46:55 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* <-- Define Section --> */

# define WIDTH 512
# define HEIGHT 512
# define RED "\033[0;31m"
# define RESET "\033[0m"
# define YELLOW "\033[0;33m"
# define ERROR_LOG RED"[ERROR]"RESET
# define INFO_LOG YELLOW"[LOG]"RESET
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'

/* <-- Libraries Section --> */

# include "BFL.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* Typedef Section */

typedef struct s_player			t_player;
typedef struct s_map			t_map;
typedef struct s_collectible	t_collectible;
typedef struct s_exit_map		t_exit_map;
typedef struct s_info			t_info;
typedef struct s_parser			t_parser;

enum e_exit_status_2
{
	INVALID_ARGS = EXIT_STATUS_LIMIT,
	INVALID_FD,
	INVALID_MAP,
	INVALID_MAP_EXTENSION,
	INVALID_MAP_FILE,
	INVALID_SIZE,
	INVALID_CHARACTER,
	INVALID_NOT_CLOSED,
	INVALID_PLAYER_AMOUNT,
	INVALID_COLLECTIBLE_AMOUNT,
	INVALID_EXIT_AMOUNT
};

enum e_type
{
	T_PLAYER,
	T_COLLECTIBLE,
	T_EXIT,
	TYPE
};

struct s_player
{
	int	x;
	int	y;
};

struct s_map
{
	char	**map;
	int		width;
	int		height;
};

struct s_collectible
{
	int		x;
	int		y;
	int		amount;
	t_bool	is_collected;
};

struct s_exit_map
{
	int		x;
	int		y;
	t_bool	is_opened;
};

struct s_parser
{
	t_bool	is_fd_opened;
	int		fd;
	char	*line;
	int		amount[TYPE];
};

struct s_info
{
	char			invalid_character;
	char			*map_name;
	t_map			map;
	t_player		player;
	t_collectible	collectible;
	t_exit_map		exit_map;
	t_parser		parser;
};

/* Function Section */

// Utils

void	parse_line(t_info *info);
void	fill_map(t_info *info);
void	ft_exit(t_info *info, int status);
void	ft_open(t_info *info);
void	ft_close(t_info *info);

#endif // SO_LONG_H
