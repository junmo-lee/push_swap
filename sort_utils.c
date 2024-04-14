/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:48:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:29:25 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*at(t_node *list, int idx)
{
	if (idx > 0)
	{
		while (idx--)
		{
			if (list->next == NULL)
				return (NULL);
			list = list->next;
		}
	}
	else
	{
		while (idx++)
		{
			if (list->prev == NULL)
				return (NULL);
			list = list->prev;
		}
	}
	return (list);
}

int	is_sorted(t_node *start, t_node *end, int is_ascending)
{
	if (is_ascending == 1)
	{
		while (start != end)
		{
			if (start->next->val < start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
	else
	{
		while (start != end)
		{
			if (start->next->val > start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
}
