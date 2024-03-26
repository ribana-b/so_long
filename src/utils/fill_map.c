/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 21:45:57 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/26 21:46:02 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_info *info)
{
	int	index;

	ft_open(info);
	info->parser.line = get_next_line(info->parser.fd);
	if (!info->parser.line)
		ft_exit(info, RIP_MALLOC);
	info->map.map = malloc((info->map.height + 1) * sizeof(*info->map.map));
	if (!info->map.map)
		ft_exit(info, RIP_MALLOC);
	info->map.map[info->map.height] = NULL;
	index = -1;
	while (info->parser.line)
	{
		info->parser.line[ft_strlen(info->parser.line) - 1] = '\0';
		info->map.map[++index] = ft_strdup(info->parser.line);
		if (!info->map.map[index])
			ft_exit(info, RIP_MALLOC);
		ft_free(&info->parser.line, 1);
		info->parser.line = get_next_line(info->parser.fd);
	}
	ft_close(info);
}
