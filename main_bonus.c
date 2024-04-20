/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/20 15:51:31 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	print_error_ret1(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	is_a_sorted(t_stack stack)
{
	int		pre;
	t_node	*i;

	if (stack.b_head != NULL || stack.b_tail != NULL)
		return (1);
	pre = INT_MIN;
	i = stack.a_head;
	while (i->next != NULL)
	{
		if (pre < i->val)
			pre = i->val;
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
	char	*input;

	flag = 0;
	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	while (flag != 10)
	{
		input = get_next_line(STDIN_FILENO);
		if (input == NULL)
			break ;
		flag = get_oper(&stack, input);
		ft_memset(input, 0, ft_strlen(input));
		free(input);
		if (flag == 5)
			return (print_error_ret1());
	}
	if (is_a_sorted(stack) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
