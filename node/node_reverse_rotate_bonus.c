/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:53 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/09 22:02:50 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	rra(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL || stack->a_head == stack->a_tail)
		return (1);
	temp = stack->a_tail->pre;
	stack->a_tail->next = stack->a_head;
	stack->a_head->pre = stack->a_tail;
	stack->a_head = stack->a_tail;
	stack->a_head->pre = NULL;
	temp->next = NULL;
	stack->a_tail = temp;
	return (0);
}

int	rrb(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL || stack->b_head == stack->b_tail)
		return (1);
	temp = stack->b_tail->pre;
	stack->b_tail->next = stack->b_head;
	stack->b_head->pre = stack->b_tail;
	stack->b_head = stack->b_tail;
	stack->b_head->pre = NULL;
	temp->next = NULL;
	stack->b_tail = temp;
	return (0);
}

int	rrr(t_stack *stack)
{
	return (rra(stack) + rrb(stack));
}