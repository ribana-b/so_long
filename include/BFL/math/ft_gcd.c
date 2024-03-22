/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:30 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 18:50:22 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

size_t	ft_gcd(size_t number1, size_t number2)
{
	size_t	temp;

	while (number2 != 0)
	{
		temp = number1;
		number1 = number2;
		number2 = temp % number2;
	}
	return (number1);
}
