/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 15:52:49 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	print_error_ret1(void)
{
	write(STDOUT_FILENO, "Error\n", 7);
	return (1);
}

// a의 배열이 오름차순으로 있는지
int	check_sort(t_stack stack)
{
	int		prev;
	t_node	*i;

	if (stack.b_head != NULL || stack.b_tail != NULL)
		return (1);
	prev = INT_MIN;
	i = stack.a_head;
	while (i->next != NULL)
	{
		if (prev < i->val)
			prev = i->val;
		else
			return (1);
		i = i->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	int		flag;

	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	flag = 0;
	while (flag != 10)
	{
		flag = get_oper(&stack);
		if (flag == 5)
			return (print_error_ret1());
	}
	if (check_sort(stack) == 0)
		write(STDIN_FILENO, "OK\n", 4);
	else
		write(STDIN_FILENO, "KO\n", 4);
}
