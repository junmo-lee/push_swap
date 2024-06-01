/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:27:22 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/01 22:10:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_case(t_param *param, long len)
{
	long	i;

	i = 0;
	param->min_val = LONG_MAX;
	while (i != len)
	{
		if (param->a_pa[i] >= 0 && param->b_pa[i] >= 0)
			param->ways = max_l2(param->a_pa[i], param->b_pa[i]);
		else if (param->a_pa[i] <= 0 && param->b_pa[i] <= 0)
			param->ways = abs_l(min_l2(param->a_pa[i], param->b_pa[i]));
		else if (param->a_pa[i] >= 0 && param->b_pa[i] <= 0)
			param->ways = param->a_pa[i] + abs_l(param->b_pa[i]);
		else if (param->a_pa[i] <= 0 && param->b_pa[i] >= 0)
			param->ways = abs_l(param->a_pa[i]) + param->b_pa[i];
		if (param->ways < param->min_val)
		{
			param->min_idx = i;
			param->min_val = param->ways;
		}
		i++;
	}
}

void	greedy_main(t_stack *stack)
{
	t_param	param;
	t_node	*temp;
	long	i;

	param_init(stack, &param);
	param.a_pa = malloc(param.b_size * sizeof(long));
	param.b_pa = malloc(param.b_size * sizeof(long));
	temp = stack->b_head;
	i = 0;
	while (temp != NULL)
	{
		param.b_pa[i] = find_close(param.b_size, i);
		param.a_pa[i] = cal_a_pre_pa(stack, &param, temp->val);
		i++;
		temp = temp->next;
	}
	find_min_case(&param, i);
	do_best_oper(stack, &param);
	free(param.a_pa);
	free(param.b_pa);
}

void	do_sorting(t_stack *stack, long *arr_lis, long *arr_stackb)
{
	arr_lis = do_lis(stack);
	arr_stackb = del_duplication(stack, arr_lis);
	pb_quick_sort(arr_stackb, 0, get_lis_len(arr_stackb) - 1);
	split_3(stack, arr_lis, arr_stackb);
	while (stack->b_head != NULL)
		greedy_main(stack);
	final_stage(stack);
}
