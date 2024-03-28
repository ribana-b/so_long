/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:28:01 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/28 08:59:09 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* <-- Define Section --> */

# ifndef SEED
#  define SEED 42
# endif // SEED

# define WIDTH 1280
# define HEIGHT 720
# define RESIZE 64
# define ERROR_LOG "\033[0;31m[ERROR] \033[0m"
# define INFO_LOG "\033[0;33m[INFO] \033[0m"
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define FILL '.'
# define PATH "./sprites/"

/* <-- Libraries Section --> */

# include "BFL.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* Typedef Section */

typedef enum e_color			t_color;
typedef struct s_player			t_player;
typedef struct s_map			t_map;
typedef struct s_collectible	t_collectible;
typedef struct s_exit_map		t_exit_map;
typedef struct s_info			t_info;
typedef struct s_parser			t_parser;
typedef struct s_sprite			t_sprite;

enum e_exit_status_2
{
	INVALID_ARGS = EXIT_STATUS_LIMIT,
	INVALID_FD,
	INVALID_MAP,
	INVALID_MAP_NAME,
	INVALID_MAP_FILE,
	INVALID_MAP_UNREACHABLE,
	INVALID_SIZE,
	INVALID_CHARACTER,
	INVALID_NOT_CLOSED,
	INVALID_PLAYER_AMOUNT,
	INVALID_COLLECTIBLE_AMOUNT,
	INVALID_EXIT_AMOUNT,
};

enum e_type
{
	T_PLAYER,
	T_COLLECTIBLE,
	T_EXIT,
	T_WALL,
	T_FLOOR,
	TYPE
};

enum e_color
{
	RED,
	YELLOW,
	PURPLE,
	GREEN,
	CYAN,
	COLOR
};

struct s_sprite
{
	mlx_image_t		*floor[COLOR];
	mlx_image_t		*wall;
	mlx_image_t		*player;
	mlx_image_t		*collectible;
	mlx_image_t		*exit_map;
	mlx_texture_t	*texture;
};

struct s_map
{
	char		**map;
	int			width;
	int			height;
	mlx_image_t	*sprite[COLOR];
	mlx_image_t	*wall_sprite;
};

struct s_parser
{
	t_bool	is_fd_opened;
	int		fd;
	char	*line;
	int		amount[TYPE];
};

struct s_player
{
	int	x;
	int	y;
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
	int			x;
	int			y;
	t_bool		is_opened;
};

struct s_info
{
	char			invalid_character;
	char			*map_name;
	t_parser		parser;
	t_map			map;
	t_player		player;
	t_collectible	collectible;
	t_exit_map		exit_map;
	t_sprite		sprite;
	mlx_t			*mlx;
	size_t			step_counter;
	unsigned long	random_number;
};

/* Function Section */

// Utils

void			parse_line(t_info *info);
void			fill_map(t_info *info);
void			parse_map(t_info *info);
void			parse_name(t_info *info);
void			ft_exit(t_info *info, int status);
void			ft_open(t_info *info);
void			ft_close(t_info *info);
void			handle_close_window(void *data);
void			handle_key_input(mlx_key_data_t keydata, void *data);
void			load_textures(t_info *info);
void			reload_textures(void *data);
void			load_floor(t_info *info);
void			load_wall(t_info *info);
void			load_player(t_info *info);
void			load_collectible(t_info *info);
void			load_exit_map(t_info *info);
void			draw_textures(t_info *info);
void			draw_map(void *data);
void			update_map(t_info *info, int new_x, int new_y);
t_bool			can_move_up(t_info *info);
t_bool			can_move_down(t_info *info);
t_bool			can_move_left(t_info *info);
t_bool			can_move_right(t_info *info);
unsigned long	ft_random(t_info *info);

#endif // SO_LONG_H
