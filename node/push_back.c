/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:16:56 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 14:37:02 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// ps_push_back(t_node** : &(stack.a_head), t_node** : &(stack.a_tail), int : add_val)
// 리스트 tail의 포인터를 받아서 마지막에 값을 추가해주고 tail을 갱신
// *head 와 *tail이 모두 NULL : 빈 리스트에 처음 값을 넣는것
// ret : 성공시 0, 실패시 1(할당 실패 등)
int	node_pb(t_node **head, t_node **tail, int val)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
		return (1);
	new->val = val; // 새로 만든 요소에 할당
	new->next = NULL;
	if (*tail == NULL && *head == NULL)
	{
		*head = new;
		*tail = new;
	}
	else
	{
		new->pre = *tail;
		(*tail)->next = new; // 원래 있던 리스트의 마지막 next가 new를 가르킴
		*tail = new; // tail을 갱신해줌
	}
	return (0);
}
