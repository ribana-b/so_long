/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 16:28:01 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 01:34:27 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/* <-- Define Section --> */

# ifndef SEED
#  define SEED 42
# endif // SEED

# define MIN_REFRESH_RATE 15
# define RESIZE 64
# define ERROR_LOG "\033[0;31m[ERROR] \033[0m"
# define INFO_LOG "\033[0;33m[INFO] \033[0m"
# define WALL '1'
# define FLOOR '0'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define ENEMY 'N'
# define FILL '.'
# define PATH "sprites/"

/* <-- Libraries Section --> */

# include "BFL.h"
# include "MLX42.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/* Typedef Section */

typedef enum e_color			t_color;
typedef enum e_type				t_type;
typedef enum e_direction		t_direction;
typedef enum e_status			t_status;
typedef struct s_player			t_player;
typedef struct s_map			t_map;
typedef struct s_collectible	t_collectible;
typedef struct s_exit_map		t_exit_map;
typedef struct s_info			t_info;
typedef struct s_parser			t_parser;
typedef struct s_sprite			t_sprite;
typedef struct s_path			t_path;

enum e_exit_status_2
{
	INVALID_ARGS = EXIT_STATUS_LIMIT,
	INVALID_FD,
	INVALID_TEXTURE,
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
	T_ENEMY,
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

enum e_status
{
	CLOSED,
	OPENED,
	STATUS
};

enum e_direction
{
	UP,
	LEFT,
	DOWN,
	RIGHT,
	DIRECTION
};

struct s_sprite
{
	mlx_image_t		*floor[COLOR];
	mlx_image_t		*wall;
	mlx_image_t		*player[DIRECTION];
	mlx_image_t		*collectible;
	mlx_image_t		*exit_map[STATUS];
	mlx_image_t		*enemy;
	mlx_texture_t	*texture;
};

struct s_path
{
	char	*floor[COLOR];
	char	*wall;
	char	*player[4];
	char	*collectible;
	char	*exit_map[STATUS];
	char	*enemy;
	char	*relative_path;
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
	int			x;
	int			y;
	int			collected;
	t_direction	current_direction;
};

struct s_collectible
{
	int		x;
	int		y;
	t_bool	is_collected;
};

struct s_exit_map
{
	int		x;
	int		y;
	t_bool	is_opened;
};

struct s_info
{
	char			invalid_character;
	char			*map_name;
	t_parser		parser;
	t_map			map;
	t_player		player;
	t_collectible	*collectible;
	t_exit_map		exit_map;
	t_sprite		sprite;
	mlx_t			*mlx;
	size_t			step_counter;
	unsigned long	random_number;
	size_t			refresh_rate;
	t_bool			force_redraw;
	t_path			path;
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
void			load_floor(t_info *info);
void			load_wall(t_info *info);
void			load_player(t_info *info);
void			load_collectible(t_info *info);
void			load_exit_map(t_info *info);
void			load_enemy(t_info *info);
void			draw_textures(void *data);
void			draw_enemy(t_info *info);
t_bool			can_move_up(t_info *info);
t_bool			can_move_down(t_info *info);
t_bool			can_move_left(t_info *info);
t_bool			can_move_right(t_info *info);
unsigned long	ft_random(t_info *info);
void			game_logic(void *data);
void			reload_player(t_info *info);
void			reload_enemy(t_info *info);
void			reload_map(t_info *info);
void			reload_collectible(t_info *info);
void			reload_exit_map(t_info *info);
void			reload_textures(t_info *info);
void			get_texture_path(t_info *info, char *map_name);
void			open_textures(t_info *info);

#endif // SO_LONG_BONUS_H
