/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:00:41 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/15 11:45:02 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *stack, long *a)
{
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
}

void	sort_2(t_stack *stack)
{
	if (stack->a_head->val > stack->a_head->next->val)
		sa(stack);
}

int	simple_sort(t_stack *stack)
{
	long	*arr;
	long	*s_arr;

	if (stack->size > 5)
		return (0);
	arr = stack_to_int_array(stack);
	s_arr = stack_to_int_array(stack);
	pb_quick_sort(s_arr, 0, stack->size - 1);
	if (!s_arr || !arr)
		return (2);
	if (stack->size == 5)
		sort_5(stack, arr, s_arr);
	else if (stack->size == 4)
		sort_4(stack, arr, s_arr);
	else if (stack->size == 3)
		sort_3(stack, s_arr);
	else if (stack->size == 2)
		sort_2(stack);
	ft_memset_long(arr, 0, stack->size + 1);
	ft_memset_long(s_arr, 0, stack->size + 1);
	free(arr);
	free(s_arr);
	return (1);
}
