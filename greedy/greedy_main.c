/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 01:27:22 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/20 08:40:28 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

long	cal_a_pre_pa(t_stack *stack, t_param *param, long b_val)
{
	t_node	*temp;
	t_node	*temp_next;
	long	i;

	i = 0;
	//위쪽 먼저 확인
	temp = stack->a_head;
	while (temp->next != NULL)
	{
		temp_next = temp->next;
		if (temp_next->val < temp->val)
			break ;
		if (temp->val < b_val && b_val < temp_next->val)
			return (find_close(param->a_size, i + 1));
		i++;
		temp = temp_next;
	}
	// temp_next->val < temp->val 에서
	// 가장 큰 값이 들어가는 경우 19 (20) 2 or 가장 작은 값이 들어가는 경우 20 (1) 2
	if (b_val > temp->val || temp_next->val > b_val)
		return (find_close(param->a_size, i + 1));
	temp = temp_next;
	i++;
	while (temp->next != NULL)
	{
		temp_next = temp->next;
		if (temp_next->val < temp->val)
			break ;
		if (temp->val < b_val && b_val < temp_next->val)
			return (find_close(param->a_size, i + 1));
		i++;
		temp = temp_next;
	}
	return (0); // 위의 케이스에 다 해당되지 않으면 맨위밖에 없음
}

void	find_min_case(t_param *param, long len)
{
	long	i;

	i = 0;
	param->min_val = LONG_MAX;
	while (i != len)
	{
		param->ways[rr_rab] = max_l2(param->a_pa[i], param->b_pa[i]);
		param->ways[rrr_rrab] = abs_l(min_l2(param->a_pa[i], param->b_pa[i]));
		param->ways[ra_rrb] = param->a_pa[i] + abs_l(param->b_pa[i]);
		param->ways[rra_rb] = abs_l(param->a_pa[i]) + param->b_pa[i];
		pb_quick_sort(param->ways, 0, 3);
		if (param->ways[0] < parma->min_val)
		{
			param->min_idx = i;
			param->min_val = param->ways[0];
		}
		i++;
	}
}

void	do_best_oper(t_stack *stack, t_param *param)
{
	long	i;

	i = param->min_idx;
	param->ways[rr_rab] = max_l2(param->a_pa[i], param->b_pa[i]);
	param->ways[rrr_rrab] = abs_l(min_l2(param->a_pa[i], param->b_pa[i]));
	param->ways[ra_rrb] = param->a_pa[i] + abs_l(param->b_pa[i]);
	param->ways[rra_rb] = abs_l(param->a_pa[i]) + param->b_pa[i];
	if (param->ways[rr_rab] == parma->min_val)
		do_rr_rrab(stack, param);
	else if (param->ways[rrr_rrab] == parma->min_val)
		do_rrr_rab(stack, param);
	else if (param->ways[ra_rrb] == parma->min_val)
		do_ra_rrb(stack, param);
	else if (param->ways[rra_rb] == parma->min_val)
		do_rra_rrb(stack, param);
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
	pa(stack);
	free(param.a_pa);
	free(param.b_pa);
}