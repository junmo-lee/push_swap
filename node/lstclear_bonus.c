/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:17:43 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 15:52:49 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// ps_lstclear_b(&(stack.a_head)) : a 스택의 head부터 리스트를 비우는것
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
