/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:35:04 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/01 18:52:16 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	sa(t_stack *stack)
{
	int	temp;

	if (stack->a_head == NULL) // 리스트가 비어있거나
		return (1);
	if (stack->a_head->next == NULL) // 하나만 존재하는 경우
		return (1);
	temp = stack->a_head->next->val;
	stack->a_head->next->val = stack->a_head->val;
	stack->a_head->val = temp;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack *stack)
{
	int	temp;

	if (stack->b_head == NULL)
		return (1);
	if (stack->b_head->next == NULL)
		return (1);
	temp = stack->b_head->next->val;
	stack->b_head->next->val = stack->b_head->val;
	stack->b_head->val = temp;
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack *stack)
{
	write(1, "ss\n", 3);
	return (sa(stack) + sb(stack));
}
