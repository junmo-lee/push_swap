/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_oper_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:15:28 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 13:12:19 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

// s가 처음 나왔을때 : sa sb ss
int	swap_oper(t_stack *stack, char *str)
{
	if (str[2] != '\n' || str[3] != '\0')
		return (5);
	if (str[1] == 'a')
		return (sa(stack));
	else if (str[1] == 'b')
		return (sb(stack));
	else if (str[1] == 's')
		return (ss(stack));
	else
		return (5);
}

int	push_oper(t_stack *stack, char *str)
{
	if (str[2] != '\n' || str[3] != '\0')
		return (5);
	if (str[1] == 'a')
		return (pa(stack));
	else if (str[1] == 'b')
		return (pb(stack));
	else
		return (5);
}

int	reverse_rotate_oper(t_stack *stack, char *str)
{
	if (str[3] != '\n' || str[4] != '\0')
		return (5);
	if (str[2] == 'a')
		return (rra(stack));
	else if (str[2] == 'b')
		return (rrb(stack));
	else if (str[2] == 'r')
		return (rrr(stack));
	return (5);
}

int	rotate_oper(t_stack *stack, char *str)
{
	if (str[1] == 'r')
	{
		if (str[2] == '\n' && str[3] == '\0')
			return (rr(stack));
		else
			return (reverse_rotate_oper(stack, str));
	}
	if (str[2] != '\n' || str[3] != '\0')
		return (5);
	if (str[1] == 'a')
		return (str[2] == ra(stack));
	else if (str[1] == 'b')
		return (rb(stack));
	return (5);
}


// stdin에서 한 줄 읽어서 맞는 함수를 실행
// ret : EOF 도달 or 읽기오류시 1, 성공시 0
// ex) while(!get_oper(&stack)) 
int	get_oper(t_stack *stack)
{
	char	*str;

	str = get_next_line(STDIN_FILENO);
	if (str == NULL)
		return (10);
	if (str[0] == 's')
		return (swap_oper(stack, str));
	else if (str[0] == 'p')
		return (push_oper(stack, str));
	else if (str[0] == 'r')
		return (rotate_oper(stack, str));
	return (5);
}
