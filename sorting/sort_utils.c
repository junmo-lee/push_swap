/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 14:48:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/02/26 16:12:56 by junmlee          ###   ########.fr       */
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

// is_ascending : 1이면 오름차순 1,2,3, 0이면 내림차순 3,2,1
// 정렬 방향대로 정렬되었으면 1 리턴, 아니면 0리턴
int	is_sorted(t_node *start, t_node *end, int is_ascending)
{
	if (is_ascending == 1)
	{
		while (start != end)
		{
			if (start->next->val < start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
	else
	{
		while (start != end)
		{
			if (start->next->val > start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
}

// 파라메터 체크하고 만드는 역할
// t_sort_param	*make_param(int len, t_node *start_node, int pos, int is_ascending)
// {
// 	t_sort_param	*ret;

// 	ret = malloc(sizeof(t_sort_param));
// 	if (ret == NULL)
// 		return (NULL);
// 	ft_memset(ret, 0, sizeof(t_sort_param));
// 	return (ret);
// }
