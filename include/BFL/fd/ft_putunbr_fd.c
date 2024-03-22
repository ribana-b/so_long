/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:44:34 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

static int	ft_putunbr(unsigned int number, int fd, int *bytes, int *success)
{
	char	*base;

	base = ft_strdup("0123456789");
	if (!base)
		return (-1);
	if (number > 0)
	{
		*bytes = ft_putunbr(number / 10, fd, bytes, success);
		if (*bytes < 0)
		{
			free(base);
			return (-1);
		}
		*success = ft_putchar_fd(base[number % 10], fd);
		if (*success < 0)
		{
			free(base);
			return (-1);
		}
	}
	free(base);
	return (*bytes + *success);
}

int	ft_putunbr_fd(unsigned int number, int fd)
{
	int	bytes_written;
	int	success;

	bytes_written = 0;
	success = 0;
	if (number == 0)
		return (ft_putchar_fd('0', fd));
	else
		return (ft_putunbr(number, fd, &bytes_written, &success));
}
