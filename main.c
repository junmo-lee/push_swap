/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 15:41:19 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error_ret1(void)
{
	write(STDOUT_FILENO, "Error\n", 7);
	return (1);
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
}
