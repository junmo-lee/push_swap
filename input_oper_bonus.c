/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_oper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/01 21:58:00 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap_oper(t_stack *stack, char *str)
{
	if (str[2] != '\n' || str[3] != '\0')
		return (1);
	if (str[1] == 'a')
		return (sa_b(stack));
	else if (str[1] == 'b')
		return (sb_b(stack));
	else if (str[1] == 's')
		return (ss_b(stack));
	else
		return (1);
}

int	push_oper(t_stack *stack, char *str)
{
	if (str[2] != '\n' || str[3] != '\0')
		return (1);
	if (str[1] == 'a')
		return (pa_b(stack));
	else if (str[1] == 'b')
		return (pb_b(stack));
	else
		return (1);
}

int	reverse_rotate_oper(t_stack *stack, char *str)
{
	if (str[3] != '\n' || str[4] != '\0')
		return (1);
	if (str[2] == 'a')
		return (rra_b(stack));
	else if (str[2] == 'b')
		return (rrb_b(stack));
	else if (str[2] == 'r')
		return (rrr_b(stack));
	return (1);
}

int	rotate_oper(t_stack *stack, char *str)
{
	if (str[1] == 'r')
	{
		if (str[2] == '\n' && str[3] == '\0')
			return (rr_b(stack));
		else
			return (reverse_rotate_oper(stack, str));
	}
	if (str[2] != '\n' || str[3] != '\0')
		return (1);
	if (str[1] == 'a')
		return (str[2] == ra_b(stack));
	else if (str[1] == 'b')
		return (rb_b(stack));
	return (1);
}

int	get_oper(t_stack *stack, char *str)
{
	if (str[0] == 's')
		return (swap_oper(stack, str));
	else if (str[0] == 'p')
		return (push_oper(stack, str));
	else if (str[0] == 'r')
		return (rotate_oper(stack, str));
	return (1);
}
