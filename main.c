/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/15 14:48:36 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *start, t_node *end, int is_ascending)
{
	if (is_ascending == 1)
	{
		while (start != end)
		{
			if (start->next->val < start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
	else
	{
		while (start != end)
		{
			if (start->next->val > start->val)
				return (0);
			start = start->next;
		}
		return (1);
	}
}

int	print_error_ret1(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

void	ft_memset_long(long *arr, long val, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		*arr = val;
		arr++;
		i++;
	}
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
	long	*del_dup;

	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	if (simple_sort(&stack) == 2)
		return (print_error_ret1());
	if (is_sorted(stack.a_head, stack.a_tail, 1) == 1)
		return (0);
	arr_lis = do_lis(&stack);
	del_dup = stack_to_int_array_del_dup(&stack, arr_lis);
	pb_quick_sort(del_dup, 0, get_lis_len(del_dup) - 1);
	split_3(&stack, arr_lis, del_dup);
	while (stack.b_head != NULL)
		greedy_main(&stack);
	final_stage(&stack);
}
