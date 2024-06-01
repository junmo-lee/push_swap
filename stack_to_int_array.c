/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:22 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/01 22:05:00 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*stack_to_int_array(t_stack *stack, long size)
{
	long	*arr;
	t_node	*temp;
	long	i;

	arr = (long *)malloc((size + 1) * sizeof(long));
	if (arr == NULL)
		return (NULL);
	ft_memset_long(arr, LONG_MIN, size + 1);
	i = 0;
	temp = stack->a_head;
	while (i < size)
	{
		arr[i++] = temp->val;
		temp = temp->next;
	}
	arr[i] = 0;
	return (arr);
}

long	*del_duplication(t_stack *stack, long *ans)
{
	long	*arr;
	t_node	*temp;
	long	i;
	long	j;

	arr = (long *)malloc((stack->size + 1) * sizeof(long));
	if (arr == NULL)
		return (NULL);
	ft_memset_long(arr, LONG_MIN, stack->size + 1);
	i = 0;
	j = 0;
	temp = stack->a_head;
	while (temp != NULL)
	{
		if (temp->val == ans[j])
			j++;
		else
			arr[i++] = temp->val;
		temp = temp->next;
	}
	arr[i] = LONG_MIN;
	return (arr);
}
