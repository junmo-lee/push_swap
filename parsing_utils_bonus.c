/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:54:34 by junmlee           #+#    #+#             */
/*   Updated: 2023/12/08 22:00:30 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ps_push_back(t_parsing **lst, t_parsing *new, t_parsing **cache)
{
	t_parsing	*temp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		if (*cache == NULL)
		{
			temp = *lst;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
			*cache = new;
		}
		else
		{
			(*cache)->next = new;
			*(cache) = new;
		}
	}
}

void	*ps_lstclear_null(t_parsing **lst)
{
	t_parsing	*temp;

	if (lst == NULL)
		return (NULL);
	while (*lst != NULL)
	{
		temp = *lst;
		*lst = (*lst)->next;
		free(temp);
	}
	return (NULL);
}
