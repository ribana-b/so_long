/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:45:28 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:45:28 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

int	ft_putchar_fd(char character, int fd)
{
	int	bytes_written;

	if (fd < 0)
		return (-1);
	bytes_written = write(fd, &character, 1);
	if (bytes_written < 0)
		return (-1);
	return (bytes_written);
}
