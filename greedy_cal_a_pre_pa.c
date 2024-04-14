/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_cal_a_pre_pa.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 17:38:00 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 22:05:59 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	cal_a_pre_pa_1(t_param *param, t_node *temp, long b_val, long *i);
long	cal_a_pre_pa_2(t_param *param, t_node *temp, long b_val, long *i);

long	cal_a_pre_pa(t_stack *stack, t_param *param, long b_val)
{
	long	i;
	t_node	*temp;

	i = 0;
	temp = stack->a_head;
	return (cal_a_pre_pa_1(param, temp, b_val, &i));
}

long	cal_a_pre_pa_1(t_param *param, t_node *temp, long b_val, long *i)
{
	t_node	*temp_next;

	while (temp->next != NULL)
	{
		temp_next = temp->next;
		if (temp_next->val < temp->val)
			break ;
		if (temp->val < b_val && b_val < temp_next->val)
			return (find_close(param->a_size, (*i) + 1));
		(*i)++;
		temp = temp_next;
	}
	if (temp_next == NULL)
		return (1);
	if (b_val > temp->val || temp_next->val > b_val)
		return (find_close(param->a_size, (*i) + 1));
	else
		return (cal_a_pre_pa_2(param, temp_next, b_val, i));
}

long	cal_a_pre_pa_2(t_param *param, t_node *temp, long b_val, long *i)
{
	t_node	*temp_next;

	(*i)++;
	while (temp->next != NULL)
	{
		temp_next = temp->next;
		if (temp_next->val < temp->val)
			break ;
		if (temp->val < b_val && b_val < temp_next->val)
			return (find_close(param->a_size, (*i) + 1));
		(*i)++;
		temp = temp_next;
	}
	return (0);
}
