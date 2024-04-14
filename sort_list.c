/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:49 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:22:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // 나중에 없애기
#include "push_swap.h"

// int	split(t_stack *stack)
// {
// 	t_node	*temp;
// 	int		*lis_arr;
// 	int		*lis;
// 	int		a_size;
// 	int		idx_a;

// 	a_size = stack->size;
// 	// a_head와 a_tail 이 같을때까지 반복(비어있을때까지)
// 	while (stack->a_head != stack->a_tail)
// 	{
// 		// lis_arr로 복사해오기
// 		idx_a = 0;
// 		lis_arr = (int *)malloc(sizeof(int) * a_size);
// 		temp = stack->a_head;
// 		while (temp->next != NULL)
// 		{
// 			lis_arr[idx_a++] = temp->val;
// 			temp = temp->next;
// 		}
// 		// lis 만들기, 0으로 끝나는 것을 확인
// 		lis = make_lis(lis_arr, idx_a);
// 		// 다시 a스택을 돌면서 lis 이면 pb하기
// 		temp = stack->a_head;
// 		while (temp->next != NULL)
// 		{
// 			if (is_in(temp->val, lis))
// 				pb(stack);
// 			else
// 				ra(stack);
// 			temp = temp->next;
// 		}
// 		a_size -= idx_a;
// 	}
// 	return (0);
// }

// int	*make_lis(int *lis_arr, int num)
// {
// 	return (NULL);
// }

// int	merge(t_stack *stack, t_command *command)
// {
// 	return (0);
// }

// int	sort(t_stack *stack, t_command *command)
// {
// 	if (split(stack) == 1)
// 		return (0);
// 	return (merge(stack, command));

// }
