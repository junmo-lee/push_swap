/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/01 22:10:34 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error_ret1(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

long	*do_lis(t_stack *stack)
{
	long	*arr;
	long	*ans;
	long	*dp;
	long	*temp;

	arr = stack_to_int_array(stack, stack->size);
	if (arr == NULL)
		return (NULL);
	dp = malloc((stack->size + 1) * sizeof(long));
	if (dp == NULL)
		return (NULL);
	ft_memset_long(dp, LONG_MIN, stack->size + 1);
	temp = malloc((stack->size + 2) * sizeof(long));
	if (temp == NULL)
		return (NULL);
	ft_memset_long(temp, LONG_MIN, stack->size + 2);
	ans = make_lis(arr, dp, temp, stack->size);
	free(arr);
	free(dp);
	free(temp);
	return (ans);
}

int	main(int argc, char *argv[])
{
	t_stack	stack;
	long	*arr_lis;
	long	*arr_stackb;
	int		ret;

	main_init(&stack, &arr_lis, &arr_stackb, &ret);
	if (parse(argc, argv, &stack) == 1)
		ret = print_error_ret1();
	else if (simple_sort(&stack) == 2)
		ret = print_error_ret1();
	else if (is_sorted(stack.a_head, stack.a_tail) == 1)
		ret = 0;
	else
		do_sorting(&stack, arr_lis, arr_stackb);
	return (clear_ret(&stack, arr_lis, arr_stackb, ret));
}
