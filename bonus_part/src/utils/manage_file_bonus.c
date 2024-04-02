/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 23:03:58 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/04/02 23:37:10 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_open(t_info *info)
{
	info->parser.fd = open(info->map_name, O_RDONLY);
	if (info->parser.fd < 0)
		ft_exit(info, INVALID_FD);
	info->parser.is_fd_opened = TRUE;
}

void	ft_close(t_info *info)
{
	if (info->parser.is_fd_opened)
		close(info->parser.fd);
	info->parser.is_fd_opened = FALSE;
}
