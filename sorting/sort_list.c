/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:44:49 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 16:54:43 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"
// 재귀 시작 : sort_list(stack->a_head, stack->a_tail, stack->size, 0)
// pos : 정렬할 리스트가 a스택에 있으면 0, b스택에 있으면 1
void	sort_list(t_node *list_head, t_node *list_tail, int len, int pos)
{
	t_node	*middle_head;
	t_node	*middle_tail;
	int		top;
	int		middle;
	int		down;

		top = len / 3 + (len % 3 == 1);
		middle = len / 3 + (len % 3 != 0);
		down = len / 3;
		middle_head = at(list_head, top);
		middle_tail = at(list_tail, -down);
		printf("%d to %d, len : %d, pos : %d\n", list_head->val, list_tail->val, len, pos);
	if (len <= 3)
	{
		return ;
	}
	else
	{
		sort_list(list_head, middle_head->prev, top, !pos);
		sort_list(middle_tail->next, list_tail, down, !pos);
		sort_list(middle_head, middle_tail, middle, pos);
	}
}
