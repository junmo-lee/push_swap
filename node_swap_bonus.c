/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:35:04 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/05 18:00:49 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	sa_b(t_stack *stack)
{
	int	temp;

	if (stack->a_head == NULL)
		return (0);
	if (stack->a_head->next == NULL)
		return (0);
	temp = stack->a_head->next->val;
	stack->a_head->next->val = stack->a_head->val;
	stack->a_head->val = temp;
	return (0);
}

int	sb_b(t_stack *stack)
{
	int	temp;

	if (stack->b_head == NULL)
		return (0);
	if (stack->b_head->next == NULL)
		return (0);
	temp = stack->b_head->next->val;
	stack->b_head->next->val = stack->b_head->val;
	stack->b_head->val = temp;
	return (0);
}

int	ss_b(t_stack *stack)
{
	return (sa_b(stack) + sb_b(stack));
}
