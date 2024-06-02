/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:45:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/02 21:06:57 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_node **head, long target)
{
	t_node	*temp;

	temp = *head;
	while (temp != NULL)
	{
		if (temp->val == target)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	add_one(char *s, t_node **head, t_node **tail)
{
	long long	val;
	int			not_num;

	not_num = 0;
	val = ps_atoll(s, &not_num);
	if (not_num == 1 || val < INT_MIN || val > INT_MAX)
		return (1);
	else if (is_duplicate(head, val) == 1)
		return (1);
	else
		return (node_pb(head, tail, (int)val));
}


int	split_space_b(char *s, t_stack *stack)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else
		{
			if (add_one(s + i, &(stack->a_head), &(stack->a_tail)) == 1)
				return (1);
			stack->size += 1;
			while (s[i] != '\0' && s[i] != ' ')
				i++;
		}
	}
	return (0);
}

int	parse(int argc, char *argv[], t_stack *stack)
{	
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (split_space_b(argv[idx], stack) == 1)
		{
			lstclear(&(stack->a_head));
			return (1);
		}
		idx++;
	}
	if (stack->size == 0)
		return (1);
	return (0);
}
