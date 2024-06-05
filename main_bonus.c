/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/05 13:38:31 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	print_error_ret1(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	is_sorted(t_node *start, t_node *end)
{
	while (start != end)
	{
		if (start->next->val < start->val)
			return (0);
		start = start->next;
	}
	return (1);
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
	if (parse(argc, argv, &stack) == 1)
		return (print_error_ret1());
	while (flag != 1)
	{
		input = get_next_line(STDIN_FILENO);
		if (input == NULL)
			break ;
		flag = get_oper(&stack, input);
		ft_memset(input, 0, ft_strlen(input));
		free(input);
		if (flag == 1)
			return (print_error_ret1());
	}
	if (is_sorted(stack.a_head, stack.a_tail) == 1)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
}
