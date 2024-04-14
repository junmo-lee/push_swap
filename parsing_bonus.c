/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:45:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 20:43:18 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	add_one(char *s, t_node **head, t_node **tail)
{
	int		val;
	t_node	*temp;

	if (s[0] == '0' && s[1] == '\0')
		return (node_pb(head, tail, 0));
	val = ps_atoll(s);
	if (val == 0 || val < INT_MIN || val > INT_MAX)
		return (1);
	temp = *head;
	while (temp != NULL)
	{
		if (temp->val == val)
			return (1);
		temp = temp->next;
	}
	return (node_pb(head, tail, (int)val));
}

int	split_space_b(char *s, t_stack *stack)
{
	int		i;

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

int	parsing(int argc, char *argv[], t_stack *stack)
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
	return (0);
}
