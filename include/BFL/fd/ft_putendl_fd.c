/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:31:08 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

int	ft_putendl_fd(const char *str, int fd)
{
	int	bytes_written;

	if (!str || fd < 0)
		return (-1);
	bytes_written = ft_putstr_fd(str, fd);
	if (bytes_written < 0)
		return (-1);
	bytes_written = ft_putchar_fd('\n', fd);
	if (bytes_written < 0)
		return (-1);
	return (bytes_written);
}
