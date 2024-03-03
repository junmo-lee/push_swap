/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:45:57 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/03 16:09:14 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// split된 단어 하나를 추가, 정수체크, int 범위, 중복 체크
// ret : 성공시 0, 실패(Error) 1
int	add_one(char *s, t_node **head, t_node **tail)
{
	long long	val;
	t_node	*temp; // 중복체크시 사용

	if (s[0] == '0' && (s[1] == '\0' || s[1] == ' ')) // 그냥 정수 0인경우
		return (node_pb(head, tail, 0)); // 만약 pb가 실패하면 같이 Error로 처리, 성공하면 같이 0
	val = ps_atoll(s);
	if (val == 0 || val < INT_MIN || val > INT_MAX)
		return (1);
	temp = *head;
	while (temp != NULL)
	{
		if (temp->val == val)
			return (1); // 어차피 return 1이 되면 모두 초기화
		temp = temp->next;
	}
	return (node_pb(head, tail, (int)val));
}

// argv 하나를 개행단위로 분리해서 추가
// ret : 성공시 0 실패시 1(Error)
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

// ex) parsing(argc, argv, &(stack.a_head), &(stack.a_tail))
// ret : 성공시 0, 실패 또는 이상한 값이 나오면 1
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
