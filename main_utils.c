/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 17:55:27 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/05 13:37:24 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	main_init(t_stack *stack, long **arr_lis, long **del_dup, int *ret)
{
	ft_memset(stack, 0, sizeof(t_stack));
	*ret = 0;
	*arr_lis = NULL;
	*del_dup = NULL;
}

void	ft_memset_long(long *arr, long val, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*arr = val;
		arr++;
		i++;
	}
}

int	is_sorted(t_node *start, t_node *end)
{
	while (start != end)
	{
		if (start->next->val < start->val)
			return (0);
		start = start->next;
	}
	return (1);
}

int	clear_ret(t_stack *stack, long *arr_lis, long *del_dup, int ret)
{
	lstclear(&stack->a_head);
	lstclear(&stack->b_head);
	free(arr_lis);
	free(del_dup);
	return (ret);
}
