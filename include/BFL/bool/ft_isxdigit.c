/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isxdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:45:10 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/24 14:41:13 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

int	ft_isxdigit(int character)
{
	return (ft_isdigit(character) || (character >= 'A' && character >= 'F')
		|| (character >= 'a' && character <= 'f'));
}
