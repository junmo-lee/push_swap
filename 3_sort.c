/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:00:41 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:22:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack)
{
	int	first;
	int	second;
	int	third;

	first = stack->a_head->val;
	second = stack->a_head->next->val;
	third = stack->a_head->next->val;
	if (first > second && second > third && first > third)
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (first < second && second > third && first < third)
	{
		rra(stack, 1);
		sa(stack);
	}
	else if (first > second && second < third && first < third)
		sa(stack);
	else if (first < second && second > third && first > third)
		rra(stack, 1);
	else if (first > second && second < third && first > third)
		ra(stack, 1);
}

void	sort_2(t_stack *stack)
{
	if (stack->a_head->val > stack->a_head->next->val)
		sa(stack);
}

void	simple_sort(t_stack *stack)
{
	if (stack->size == 3)
		sort_3(stack);
	else if (stack->size == 2)
		sort_2(stack);
	else
		return ;
}
