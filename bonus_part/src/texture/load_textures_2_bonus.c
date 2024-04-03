/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:49:07 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/03 00:04:41 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	load_enemy(t_info *info)
{
	info->sprite.texture = mlx_load_png(info->path.enemy);
	info->sprite.enemy = mlx_texture_to_image(info->mlx, info->sprite.texture);
	mlx_delete_texture(info->sprite.texture);
}
