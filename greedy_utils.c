/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:32:59 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:34:21 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	param_init(t_stack *stack, t_param *param)
{
	t_node	*temp;

	ft_memset(param, 0, sizeof(t_param));
	param->a_size++;
	param->b_size++;
	temp = stack->a_head;
	while (temp->next != NULL)
	{
		param->a_size++;
		temp = temp->next;
	}
	temp = stack->b_head;
	while (temp->next != NULL)
	{
		param->b_size++;
		temp = temp->next;
	}
}

long	find_close(long b_size, long idx)
{
	if (idx <= (b_size / 2))
		return (idx);
	else
		return (idx - b_size);
}

long	max_l2(long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	min_l2(long a, long b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

long	abs_l(long a)
{
	if (a > 0)
		return (a);
	else
		return (-a);
}
