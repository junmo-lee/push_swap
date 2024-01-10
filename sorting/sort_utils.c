/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:48:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 16:06:17 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// 연결리스트 접근, idx가 양수면 head로부터 next, 음소면 tail부터 prev
// ret : 해당 노드 포인터
// ex) a : 2 1 3 6 5 8
// ex) at(stack->a_head, 2)->val == 3
// ex) at(stack->a_tail, -2)->val == 6
t_node	*at(t_node *list, int idx)
{
	if (idx > 0)
	{
		while (idx--)
		{
			if (list->next == NULL)
				return (NULL);
			list = list->next;
		}
	}
	else
	{
		while (idx++)
		{
			if (list->prev == NULL)
				return (NULL);
			list = list->prev;
		}
	}
	return (list);
}
