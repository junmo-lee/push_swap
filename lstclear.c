/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:17:43 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/15 17:55:56 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lstclear(t_node **lst)
{
	t_node	*temp;

	while (*lst != NULL)
	{
		temp = *lst;
		temp->next = NULL;
		temp->prev = NULL;
		temp->val = 0;
		*lst = (*lst)->next;
		free(temp);
	}
}
