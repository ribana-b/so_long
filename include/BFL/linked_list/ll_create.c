/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ribana-b <ribana-b@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:46:25 by ribana-b          #+#    #+# Malaga      */
/*   Updated: 2024/03/24 14:52:58 by ribana-b         ###   ########.com      */
/*                                                                            */
/* ************************************************************************** */

#include "BFL.h"

static void	ll_initialize(t_ll **linked_list)
{
	if (!(*linked_list))
		return ;
	(*linked_list)->content = NULL;
	(*linked_list)->next = NULL;
	return ;
}

t_ll	*ll_create_node(void)
{
	t_ll	*linked_list;

	linked_list = (t_ll *)malloc(sizeof(t_ll));
	if (!linked_list)
		return (NULL);
	ll_initialize(&linked_list);
	return (linked_list);
}

void	ll_add_node(t_ll **linked_list)
{
	t_ll	*newnode;

	if (!(*linked_list))
		return ;
	newnode = ll_create_node();
	if (!newnode)
		return ;
	(*linked_list)->next = newnode;
}

t_ll	*ll_generator(int length)
{
	t_ll	*linked_list;
	t_ll	*temp;

	if (length < 1)
		return (NULL);
	linked_list = ll_create_node();
	if (!linked_list)
		return (NULL);
	if (length == 1)
		return (linked_list);
	temp = linked_list;
	while (length-- > 1)
	{
		ll_add_node(&temp);
		if (!temp->next)
		{
			ll_destroy(&linked_list);
			return (NULL);
		}
		temp = temp->next;
	}
	return (linked_list);
}
