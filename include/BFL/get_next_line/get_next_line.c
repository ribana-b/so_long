/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:17 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:50:06 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static char	*ft_strjoin_gnl(char *str, const char *str2)
{
	char	*new_str;
	int		index;
	int		index2;

	index = ft_strlen(str);
	index2 = ft_strlen(str2);
	new_str = (char *)malloc((index + index2 + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[index + index2] = '\0';
	while (index2-- > 0)
		new_str[index + index2] = str2[index2];
	while (index-- > 0)
		new_str[index] = str[index];
	free(str);
	return (new_str);
}

static char	*read_file(char *temp, int fd)
{
	char	*buffer;
	int		bytes_read;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free(temp);
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(temp, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buffer);
			free(temp);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp = ft_strjoin_gnl(temp, buffer);
	}
	free(buffer);
	return (temp);
}

static char	*read_temp(char *temp)
{
	char	*line;
	int		index;

	if (!(*temp))
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
		index++;
	line = (char *)malloc((index + 2) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
	{
		line[index] = temp[index];
		index++;
	}
	line[index] = temp[index];
	line[index + 1] = '\0';
	return (line);
}

static char	*read_temp_again(char *temp)
{
	char	*new_temp;
	int		index;
	int		index2;

	if (!temp)
		return (NULL);
	index = 0;
	while (temp[index] != '\n' && temp[index] != '\0')
		index++;
	if (temp[index] == '\n')
		index++;
	index2 = 0;
	while (temp[index + index2] != '\0')
		index2++;
	new_temp = (char *)malloc((index2 + 1) * sizeof(char));
	if (!new_temp)
		return (NULL);
	index2 = -1;
	while (temp[index + ++index2] != '\0')
		new_temp[index2] = temp[index + index2];
	new_temp[index2] = '\0';
	free(temp);
	return (new_temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!temp)
	{
		temp = ft_calloc(1, sizeof(char));
		if (!temp)
			return (NULL);
	}
	temp = read_file(temp, fd);
	if (!temp)
		return (NULL);
	line = read_temp(temp);
	if (!(*temp))
	{
		free(temp);
		temp = NULL;
	}
	temp = read_temp_again(temp);
	return (line);
}
