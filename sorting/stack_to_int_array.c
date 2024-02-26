/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_to_int_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 16:15:22 by junmlee           #+#    #+#             */
/*   Updated: 2024/02/26 16:26:33 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	*stack_to_int_array(t_stack *stack)
{
	int		*arr;
	t_node	*temp;
	int		i;

	arr = (int *)malloc(stack->size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	ft_memset(arr, stack->size, sizeof(int));
	i = 0;
	temp = stack->a_head;
	while (i < stack->size)
	{
		arr[i++] = temp->val;
		temp = temp->next;
	}
	return (arr);
}