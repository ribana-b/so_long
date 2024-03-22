/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:26 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/22 15:46:26 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "bfl.h"

void	ll_destroy_content(t_ll **linked_list)
{
	if (!(*linked_list) || !((*linked_list)->content))
		return ;
	free((*linked_list)->content);
	(*linked_list)->content = NULL;
	return ;
}

void	ll_destroy(t_ll **linked_list)
{
	t_ll	*temp;

	if (!(*linked_list))
		return ;
	while (*linked_list)
	{
		temp = (*linked_list)->next;
		ll_destroy_content(linked_list);
		free(*linked_list);
		*linked_list = temp;
	}
	return ;
}
