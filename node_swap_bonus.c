/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:35:04 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:27:36 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

int	sa_b(t_stack *stack)
{
	int	temp;

	if (stack->a_head == NULL)
		return (1);
	if (stack->a_head->next == NULL)
		return (1);
	temp = stack->a_head->next->val;
	stack->a_head->next->val = stack->a_head->val;
	stack->a_head->val = temp;
	return (0);
}

int	sb_b(t_stack *stack)
{
	int	temp;

	if (stack->b_head == NULL)
		return (1);
	if (stack->b_head->next == NULL)
		return (1);
	temp = stack->b_head->next->val;
	stack->b_head->next->val = stack->b_head->val;
	stack->b_head->val = temp;
	return (0);
}

int	ss_b(t_stack *stack)
{
	return (sa_b(stack) + sb_b(stack));
}
