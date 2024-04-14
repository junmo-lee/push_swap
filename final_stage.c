/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_stage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 16:38:43 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 21:49:04 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_ra_or_rra(t_stack *stack, int min_val_idx)
{
	int	ra_oper;
	int	rra_oper;

	ra_oper = min_val_idx;
	rra_oper = stack->size - min_val_idx;
	if (ra_oper < rra_oper)
	{
		while (ra_oper-- > 0)
			ra(stack, 1);
	}
	else
	{
		while (rra_oper-- > 0)
			rra(stack, 1);
	}
}

void	final_stage(t_stack *stack)
{
	t_node	*temp;
	long	min_val;
	long	i;
	long	min_val_idx;

	if (is_sorted(stack->a_head, stack->a_tail, 1))
		return ;
	temp = stack->a_head;
	min_val = LONG_MAX;
	i = 0;
	while (temp != NULL)
	{
		if (temp->val < min_val)
		{
			min_val = temp->val;
			min_val_idx = i;
		}
		temp = temp->next;
		i++;
	}
	last_ra_or_rra(stack, min_val_idx);
}
