/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexu_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:05:11 by ribana-b          #+#    #+#             */
/*   Updated: 2024/02/14 12:48:59 by ribana-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

static int	ft_puthex(unsigned long long n, int fd, int *bytes, int *success)
{
	char	*base;

	base = ft_strdup("0123456789ABCDEF");
	if (!base)
		return (-1);
	if (n > 0)
	{
		*bytes = ft_puthex(n / 16, fd, bytes, success);
		if (*bytes < 0)
		{
			free(base);
			return (-1);
		}
		*success = ft_putchar_fd(base[n % 16], fd);
		if (*success < 0)
		{
			free(base);
			return (-1);
		}
	}
	free(base);
	return (*bytes + *success);
}

int	ft_puthexu_fd(unsigned long long n, int fd)
{
	int	bytes_written;
	int	success;

	bytes_written = 0;
	success = 0;
	if (n == 0)
		return (ft_putchar_fd('0', fd));
	else
		return (ft_puthex(n, fd, &bytes_written, &success));
}
