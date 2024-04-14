/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_do_oper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 08:25:38 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 16:36:50 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_rr_rab(t_stack *stack, t_param *param)
{
	long	ra_num;
	long	rb_num;

	ra_num = param->a_pa[param->min_idx];
	rb_num = param->b_pa[param->min_idx];
	while (ra_num > 0 && rb_num > 0)
	{
		rr(stack);
		ra_num--;
		rb_num--;
	}
	while (rb_num > 0)
	{
		rb(stack, 1);
		rb_num--;
	}
	while (ra_num > 0)
	{
		ra(stack, 1);
		ra_num--;
	}
}

void	do_rrr_rrab(t_stack *stack, t_param *param)
{
	long	rra_num;
	long	rrb_num;

	rra_num = abs_l(param->a_pa[param->min_idx]);
	rrb_num = abs_l(param->b_pa[param->min_idx]);
	while (rra_num > 0 && rrb_num > 0)
	{
		rrr(stack);
		rra_num--;
		rrb_num--;
	}
	while (rrb_num > 0)
	{
		rrb(stack, 1);
		rrb_num--;
	}
	while (rra_num > 0)
	{
		rra(stack, 1);
		rra_num--;
	}
}

void	do_ra_rrb(t_stack *stack, t_param *param)
{
	long	ra_num;
	long	rrb_num;

	ra_num = param->a_pa[param->min_idx];
	rrb_num = abs_l(param->b_pa[param->min_idx]);
	while (rrb_num > 0)
	{
		rrb(stack, 1);
		rrb_num--;
	}
	while (ra_num > 0)
	{
		ra(stack, 1);
		ra_num--;
	}
}

void	do_rra_rb(t_stack *stack, t_param *param)
{
	long	rra_num;
	long	rb_num;

	rra_num = abs_l(param->a_pa[param->min_idx]);
	rb_num = param->b_pa[param->min_idx];
	while (rb_num > 0)
	{
		rb(stack, 1);
		rb_num--;
	}
	while (rra_num > 0)
	{
		rra(stack, 1);
		rra_num--;
	}
}

void	do_best_oper(t_stack *stack, t_param *param)
{
	long	i;

	i = param->min_idx;
	// param->ways[rr_rab] = max_l2(param->a_pa[i], param->b_pa[i]);
	// param->ways[rrr_rrab] = abs_l(min_l2(param->a_pa[i], param->b_pa[i]));
	// param->ways[ra_rrb] = param->a_pa[i] + abs_l(param->b_pa[i]);
	// param->ways[rra_rb] = abs_l(param->a_pa[i]) + param->b_pa[i];
	if (param->a_pa[i] >= 0 && param->b_pa[i] >= 0)
		do_rr_rab(stack, param);
	else if (param->a_pa[i] <= 0 && param->b_pa[i] <= 0)
		do_rrr_rrab(stack, param);
	else if (param->a_pa[i] >= 0 && param->b_pa[i] <= 0)
		do_ra_rrb(stack, param);
	else if (param->a_pa[i] <= 0 && param->b_pa[i] >= 0)
		do_rra_rb(stack, param);
	// if (param->ways[rr_rab] == param->min_val)
	// 	do_rr_rab(stack, param);
	// else if (param->ways[rrr_rrab] == param->min_val)
	// 	do_rrr_rrab(stack, param);
	// else if (param->ways[ra_rrb] == param->min_val)
	// 	do_ra_rrb(stack, param);
	// else if (param->ways[rra_rb] == param->min_val)
	// 	do_rra_rb(stack, param);
	pa(stack);
}