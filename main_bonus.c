/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/09 16:55:31 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_stack stack;
	stack.a_head = NULL;
	stack.b_head = NULL;
	stack.a_tail = NULL;
	stack.b_tail = NULL;

	if (parsing(argc, argv, &(stack.a_head), &stack.a_tail) == 1)
		write(STDOUT_FILENO, "Error\n", 7);
}
