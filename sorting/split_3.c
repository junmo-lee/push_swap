/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:20:41 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 16:34:36 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_in_long_arr(long *arr_lis, long target)
{
	while (*arr_lis != LONG_MIN)
		if (*(arr_lis++) == target)
			return (1);
	return (0);
}

void	split_stack(t_stack *stack, long *arr_lis, long lis_len, long a)
{
	t_node	*temp;
	t_node	*temp_next;
	long	i;

	//2 6 8 9 11 12 20
	i = 0;
	temp = stack->a_head;
	while (temp != NULL && i <= lis_len)
	{
		temp_next = temp->next;
		if (is_in_long_arr(arr_lis, temp->val))
		{
			if (i != lis_len || temp->val != arr_lis[0])
				ra(stack, 1);
			i++;
		}
		else if (temp->val <= a)
			pb(stack);
		else
		{
			pb(stack);
			rb(stack, 1);
		}
		temp = temp_next;
	}
}

void	split_3(t_stack *stack, long *arr_lis, long *del_dup)
{
	long	lis_len;
	long	to_head_b_len;
	//long	to_tail_b_len;
	//long	to_tail_a_len;

	lis_len = 0;
	while (del_dup[lis_len] != LONG_MIN)
		lis_len++;
	pb_quick_sort(del_dup, 0, lis_len - 1);
	//to_head_b_len = del_dup[lis_len / 3 + (lis_len % 3 != 0)];
	//to_tail_b_len = del_dup[(2 * lis_len / 3) + (lis_len % 3 == 1)];
	//to_tail_a_len = del_dup[lis_len];
	to_head_b_len = del_dup[lis_len / 2];
	//to_tail_b_len = del_dup[lis_len];
	split_stack(stack, arr_lis, stack->size - lis_len, to_head_b_len);
}