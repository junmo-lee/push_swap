/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:38:40 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 14:36:34 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL || stack->a_head == stack->a_tail)
		return (1);
	temp = stack->a_head;
	stack->a_head = stack->a_head->next;

	stack->a_tail->next = temp;
	temp->pre = stack->a_tail;

	stack->a_tail = temp;
	stack->a_tail->next = NULL;

	return (0);
}

int	rb(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL || stack->b_head == stack->b_tail)
		return (1);
	temp = stack->b_head;
	stack->b_head = stack->b_head->next;

	stack->b_tail->next = temp;
	temp->pre = stack->b_tail;

	stack->b_tail = temp;
	stack->b_tail->next = NULL;

	return (0);
}

int	rr(t_stack *stack)
{
	return (ra(stack) + rb(stack));
}
