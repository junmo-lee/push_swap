/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:22 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/10 21:21:49 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	*stack_to_int_array(t_stack *stack)
{
	long	*arr;
	t_node	*temp;
	long	i;

	arr = (long *)malloc((stack->size + 1) * sizeof(long));
	if (arr == NULL)
		return (NULL);
	ft_memset_long(arr, LONG_MIN, stack->size + 1);
	i = 0;
	temp = stack->a_head;
	while (i < stack->size)
	{
		arr[i++] = temp->val;
		temp = temp->next;
	}
	arr[i] = 0;
	return (arr);
}

int	*stack_to_int_array_del_dup(t_stack *stack, int *ans)
{
	int		*arr;
	t_node	*temp;
	int		i;
	int		j;

	arr = (int *)malloc(stack->size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, 0, stack->size * sizeof(int));
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
	arr[i] = 0;
	return (arr);
}