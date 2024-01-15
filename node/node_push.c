/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 21:09:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/15 15:40:40 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	pb(t_stack *stack)
{
	t_node	*temp;

	if (stack->a_head == NULL)
		return (1);
	temp = stack->a_head;
	stack->a_head = stack->a_head->next;
	if (stack->a_head->next == NULL)
	{
		stack->a_head = NULL;
		stack->a_tail = NULL;
	}
	else
		stack->a_head->prev = NULL;
	temp->next = stack->b_head;
	if (stack->b_head == NULL)
		stack->b_tail = temp;
	else
		stack->b_head->prev = temp;
	stack->b_head = temp;
	stack->b_head->prev = NULL;
	return (0);
}

int	pa(t_stack *stack)
{
	t_node	*temp;

	if (stack->b_head == NULL)
		return (1);
	temp = stack->b_head;
	stack->b_head = stack->b_head->next;
	if (stack->b_head->next == NULL)
	{
		stack->b_head = NULL;
		stack->b_tail = NULL;
	}
	else
		stack->b_head->prev = NULL;
	temp->next = stack->a_head;
	if (stack->a_head == NULL)
		stack->a_tail = temp;
	else
		stack->a_head->prev = temp;
	stack->a_head = temp;
	stack->a_head->prev = NULL;
	return (0);
}
