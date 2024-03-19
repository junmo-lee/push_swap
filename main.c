/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/20 02:32:01 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());
	long *arr_lis = do_lis(&stack);
	long *del_dup = stack_to_int_array_del_dup(&stack, arr_lis);
	//pb_quick_sort(del_dup, 0, get_lis_len(del_dup) - 1);
	split_3(&stack, arr_lis, del_dup); //3단계로 나눔
	greedy_main(&stack); //그리디 시작
	//final_stage(&stack); //마지막으로 시작하는단계
	//stack_print(stack);
	//system("leaks debug.out");	
}