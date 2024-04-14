/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:38:40 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 20:43:18 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ra_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL || stack->a_head == stack->a_tail)
		return (1);
	temp = stack->a_head;
	stack->a_head = stack->a_head->next;
	stack->a_tail->next = temp;
	temp->prev = stack->a_tail;
	temp->next = NULL;
	stack->a_tail = temp;
	return (0);
}

int	rb_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL || stack->b_head == stack->b_tail)
		return (1);
	temp = stack->b_head;
	stack->b_head = stack->b_head->next;
	stack->b_tail->next = temp;
	temp->prev = stack->b_tail;
	temp->next = NULL;
	stack->b_tail = temp;
	return (0);
}

int	rr_b(t_stack *stack)
{
	return (ra_b(stack) + rb_b(stack));
}
