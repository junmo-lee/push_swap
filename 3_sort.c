/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:00:41 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/15 15:46:54 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	find_min(long *a, long size)
{
	long	ret;
	long	i;

	i = 0;
	ret = LONG_MAX;
	while (i < size)
	{
		if (ret > a[i])
			ret = a[i];
		i++;
	}
	return (ret);
}

int	sort_3(t_stack *stack, long *a)
{
	a = stack_to_int_array(stack, 3);
	if (!a)
		return (2);
	if (a[0] > a[1] && a[1] > a[2] && a[0] > a[2])
	{
		sa(stack);
		rra(stack, 1);
	}
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		rra(stack, 1);
		sa(stack);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		sa(stack);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] > a[2])
		rra(stack, 1);
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		ra(stack, 1);
	return (1);
}

int	sort_2(t_stack *stack)
{
	if (stack->a_head->val > stack->a_head->next->val)
		sa(stack);
	return (1);
}

int	simple_sort(t_stack *stack)
{
	long	*arr;
	long	max_val;

	max_val = LONG_MIN;
	arr = NULL;
	if (stack->size > 5)
		return (0);
	if (is_sorted(stack->a_head, stack->a_tail, 1) == 1)
		return (1);
	if (stack->size == 5)
		return (sort_5(stack, arr, max_val));
	else if (stack->size == 4)
		return (sort_4(stack, arr, max_val));
	else if (stack->size == 3)
		return (sort_3(stack, arr));
	else if (stack->size == 2)
		return (sort_2(stack));
	return (1);
}
