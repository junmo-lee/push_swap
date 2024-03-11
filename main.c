/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/11 21:47:00 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void stack_print(t_stack stack)
{
	t_node	*temp_a = stack.a_head;
	t_node	*temp_b = stack.b_head;
	printf("\n-- --\n a  b\n");
	while (temp_a != NULL && temp_b != NULL)
	{
		printf("%2d %2d\n", temp_a->val, temp_b->val);
		temp_a = temp_a->next;
		temp_b = temp_b->next;
	}
	while (temp_a != NULL)
	{
		printf("%2d   \n", temp_a->val);
		temp_a = temp_a->next;
	}
	while (temp_b != NULL)
	{
		printf("   %2d\n", temp_b->val);
		temp_b = temp_b->next;
	}
}


int	print_error_ret1(void)
{
	write(STDOUT_FILENO, "Error\n", 7);
	return (1);
}

// void   check_leak(void)
// {
// 		system("leaks a.out");
// }

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

	arr = stack_to_int_array(stack);
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
	//atexit(check_leak); //check_leak 함수가 프로세스 종료시 실행되도록 등록
	t_stack	stack;

	memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	stack_print(stack);
	long *arr_lis = do_lis(&stack);
	printf("LIS arr : ");
	for(int k=0;arr_lis[k] != LONG_MIN;k++)
		printf("%ld ", arr_lis[k]);
	printf("\nstack size : %ld\n", stack.size);
	printf("del dup : ");
	long *del_dup = stack_to_int_array_del_dup(&stack, arr_lis);
	for(int k=0;del_dup[k] != LONG_MIN;k++)
		printf("%ld ", del_dup[k]);
	printf("\n");
	pb_quick_sort(del_dup, 0, get_lis_len(del_dup) - 1);
	for(int k=0;del_dup[k] != LONG_MIN;k++)
		printf("%ld ", del_dup[k]);
	split_3(&stack, arr_lis, del_dup);
	stack_print(stack);
	//stack_print(stack);
	//system("leaks debug.out");	
}