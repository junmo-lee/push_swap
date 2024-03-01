/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/01 19:09:41 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"

int	print_error_ret1(void)
{
	write(STDOUT_FILENO, "Error\n", 7);
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

int main(int argc, char *argv[])
{
	t_stack stack;

	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	int flag = 0;
	while (flag != 10)
	{
		flag = get_oper(&stack);
		if (flag == 5)
			return (print_error_ret1());
	}
	if (is_a_sorted(stack) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}