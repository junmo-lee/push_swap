/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:09:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/09 23:14:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	pb(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL)
		return (1);
	temp = stack->a_head;
	stack->a_head = stack->a_head->next;
	if (stack->a_head != NULL)
		stack->a_head->pre = NULL;
	temp->next = stack->b_head;

	if (stack->b_head == NULL)
		stack->b_tail = temp;
	stack->b_head = temp;
	stack->b_head->pre = NULL;
	return (0);
}

int	pa(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL)
		return (1);
	temp = stack->b_head;
	stack->b_head = stack->b_head->next;
	if (stack->b_head != NULL)
		stack->b_head->pre = NULL;
	temp->next = stack->a_head;

	if (stack->a_head == NULL)
		stack->a_tail = temp;
	stack->a_head = temp;
	stack->a_head->pre = NULL;
	return (0);
}

