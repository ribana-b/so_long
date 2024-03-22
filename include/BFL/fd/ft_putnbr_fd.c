/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 17:02:36 by ribana-b          #+#    #+#             */
/*   Updated: 2024/03/22 18:49:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	ft_putnbr_fd(int number, int fd)
{
	char	*str;
	int		bytes_written;

	if (fd < 0)
		return (-1);
	str = ft_itoa(number);
	if (!str)
		return (-1);
	bytes_written = ft_putstr_fd(str, fd);
	free(str);
	if (bytes_written < 0)
		return (-1);
	return (bytes_written);
}
