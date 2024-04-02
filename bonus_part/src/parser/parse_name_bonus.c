/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:46:54 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/02 23:36:25 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	handle_slash(t_info *info, char ***split)
{
	char	*trimmed_name;
	size_t	length;

	trimmed_name = ft_strrchr((*split)[0], '/');
	if (!trimmed_name)
		return (KO);
	++trimmed_name;
	length = ft_strlen(trimmed_name);
	if (length < 5 || ft_strncmp(trimmed_name + length - 4, ".ber", 4) != 0)
	{
		ft_free(split, 2);
		ft_exit(info, INVALID_MAP_NAME);
	}
	return (OK);
}

static void	handle_no_slash(t_info *info, char ***split)
{
	size_t	length;

	length = ft_strlen((*split)[0]);
	if (ft_strncmp((*split)[0] + length - 4, ".ber", 4) != 0)
	{
		ft_free(split, 2);
		ft_exit(info, INVALID_MAP_NAME);
	}
}

void	parse_name(t_info *info)
{
	char	**split;

	split = ft_split(info->map_name, ' ');
	if (!split)
	{
		ft_free(&split, 2);
		ft_exit(info, RIP_MALLOC);
	}
	if (ft_splitlen(split) != 1)
	{
		ft_free(&split, 2);
		ft_exit(info, INVALID_ARGS);
	}
	if (handle_slash(info, &split) == OK)
	{
		ft_free(&split, 2);
		return ;
	}
	handle_no_slash(info, &split);
	ft_free(&split, 2);
}
