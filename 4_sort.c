/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 10:40:15 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/15 15:46:53 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_4(t_stack *stack, long *a, long max_val)
{	
	a = stack_to_int_array(stack, 4);
	if (!a)
		return (2);
	max_val = find_min(a, 4);
	if (a[1] == max_val)
		sa(stack);
	else if (a[2] == max_val)
	{
		rra(stack, 1);
		rra(stack, 1);
	}
	else if (a[3] == max_val)
		rra(stack, 1);
	pb(stack);
	sort_3(stack, a);
	pa(stack);
	ft_memset_long(a, 0, 5);
	free(a);
	return (1);
}
