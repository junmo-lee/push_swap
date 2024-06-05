/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_reverse_rotate_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:57:53 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/05 18:01:22 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rra_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL || stack->a_head == stack->a_tail)
		return (0);
	temp = stack->a_tail;
	stack->a_tail = stack->a_tail->prev;
	stack->a_tail->next = NULL;
	stack->a_head->prev = temp;
	temp->next = stack->a_head;
	temp->prev = NULL;
	stack->a_head = temp;
	return (0);
}

int	rrb_b(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL || stack->b_head == stack->b_tail)
		return (1);
	temp = stack->b_tail;
	stack->b_tail = stack->b_tail->prev;
	stack->b_tail->next = NULL;
	stack->b_head->prev = temp;
	temp->next = stack->b_head;
	temp->prev = NULL;
	stack->b_head = temp;
	return (0);
}

int	rrr_b(t_stack *stack)
{
	return (rra_b(stack) + rrb_b(stack));
}
