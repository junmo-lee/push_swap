/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:49 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/15 22:21:14 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // 나중에 없애기
#include "../push_swap.h"

//LCS, LIS 호출 해서 정렬된 부분을 확인하는 역할
//param에 sorted_n 과 sorted_arr를 넣어줌
int	sorted_part(t_stack *stack, t_sort_param *param)
{

}

int	split_stack(t_stack *stack, t_sort_param *param)
{
	t_node	*i;
	int		idx;

	i = param->start_node;
	idx = param->len;
	while (idx--)
	{
		if (in_arr(i->val, param->sorted_arr))
			reverse(stack, param);
		else if (i->val > param->middle)
		{
			push_head(stack, param);
			param->big_n++;
		}
		else
		{
			push_tail(stack, param);
			param->small_n++;
		}
		i = i->next;
	}
}

// LIS 부분 제외하고 나머지 부분 재귀로 
int	recursion(t_stack *stack, t_sort_param *param)
{
	
}

// 3개로 나누어진거 모으는 역할
int	marge_stack(t_stack *stack, t_sort_param *param)
{
	int	max;

	max = INT_MIN;
	while ((param->len)--)
	{
		if ()	
	}
}

// 성공적으로 정렬되었다면 0리턴
int	sort_list(t_stack *stack, t_sort_param *param)
{
	if (make_param(stack, param) == 1)
		return (1);
	if (is_sorted(param->start_node, at(param->start_node, param->len), param->is_ascending))
		return (0);
	if (sorted_part(stack, param) == 1)
		return (1);
	split_stack(stack, param);
	recursion(stack, param);
	marge_stack(stack, param);
	return (0);
}
