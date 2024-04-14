/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:16:56 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 20:43:18 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	node_pb(t_node **head, t_node **tail, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (1);
	new->val = val;
	new->next = NULL;
	if (*tail == NULL && *head == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		new->prev = *tail;
		(*tail)->next = new;
		*tail = new;
	}
	return (0);
}
