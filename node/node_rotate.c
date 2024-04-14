/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:38:40 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 16:32:05 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ra(t_stack *stack, int do_print)
{
	t_node	*temp;

	if (stack->a_head == NULL || stack->a_head == stack->a_tail)
		return (1);
	temp = stack->a_head;
	stack->a_head = stack->a_head->next;
	stack->a_head->prev = NULL;
	stack->a_tail->next = temp;
	temp->prev = stack->a_tail;
	temp->next = NULL;
	stack->a_tail = temp;
	if (do_print)
		write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack *stack, int do_print)
{
	t_node	*temp;

	if (stack->b_head == NULL || stack->b_head == stack->b_tail)
		return (1);
	temp = stack->b_head;
	stack->b_head = stack->b_head->next;
	stack->b_head->prev = NULL;
	stack->b_tail->next = temp;
	temp->prev = stack->b_tail;
	temp->next = NULL;
	stack->b_tail = temp;
	if (do_print)
		write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack *stack)
{
	write(1, "rr\n", 3);
	return (ra(stack, 0) + rb(stack, 0));
}
