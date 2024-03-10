/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/10 19:15:04 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error_ret1(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	return (1);
}

int	do_lis(t_stack *stack)
{
	int *arr = stack_to_int_array(stack);

	if (stack->a_head == stack->a_tail)
		return (1);
	int *dp = malloc((stack->size + 1) * sizeof(int));
	int *temp = malloc((stack->size + 2) * sizeof(int));

	if (dp == NULL || temp == NULL)
		return (1);
	ft_memset(dp, 0, (stack->size + 1) * sizeof(int));
	ft_memset(temp, 0, (stack->size + 2) * sizeof(int));
	temp[0] = -1;
	int *ans = make_lis(arr, dp, temp, stack->size);
	

	int	lis_len = get_lis_len(ans);
	int *arr_del_dup = stack_to_int_array_del_dup(stack, ans);

	ft_memset(dp, 0, (stack->size + 1) * sizeof(int));
	ft_memset(temp, 0, (stack->size + 2) * sizeof(int));
	temp[0] = -1;
	int *ans_lcs = make_lcs(arr_del_dup, dp, temp, stack->size - lis_len);

	int lis_idx = 0;
	int lcs_idx = 0;
	int arr_idx = 0;

	while (ans[lis_idx] != 0 || ans_lcs[lcs_idx] != 0)
	{
		if (arr[arr_idx] == ans[lis_idx])
		{
			pb(stack);
			lis_idx++;
		}
		else if (arr[arr_idx] == ans_lcs[lcs_idx])
		{
			pb(stack);
			rb(stack);
			lcs_idx++;
		}
		else
			ra(stack);
		arr_idx++;
	}
	stack->size -= (lis_idx + lcs_idx);
	free(dp);
	free(temp);
	return (0);
}

int	go_merge(t_stack *stack, int p_a, int p_bh, int p_bt);

int	do_merge(t_stack *stack)
{
	int	a_tail_pivot;
	int	b_head_pivot;
	int	b_tail_pivot;

	if (stack->a_tail != NULL)
		a_tail_pivot = stack->a_tail->val;
	else
		a_tail_pivot = -1;
	if (stack->b_head != NULL)
		b_head_pivot = stack->b_head->val;
	else
		b_head_pivot = -1;
	if (stack->b_tail != NULL && stack->b_tail != stack->b_head)
		b_tail_pivot = stack->b_tail->val;
	else
		b_tail_pivot = -1;
	go_merge(stack, a_tail_pivot, b_head_pivot, b_tail_pivot);
	return (0);
}

int	go_merge(t_stack *stack, int p_a, int p_bh, int p_bt)
{
	t_node	*a_tail;
	t_node	*b_head;
	t_node	*b_tail;

	int	max_val;
	int	max_part;

	a_tail = stack->a_tail;
	b_head = stack->b_head;
	b_tail = stack->b_tail;
	while (a_tail != NULL || b_head != NULL || b_tail != NULL)
	{
		max_val = -1;
		max_part = -1;
		if (p_a == -1 || a_tail == NULL || a_tail->val > p_a)
			a_tail = NULL;
		if (p_bh == -1 || b_head == NULL || b_head->val > p_bh)
			b_head = NULL;
		if (p_bt == -1 || b_tail == NULL || b_tail->val > p_bt)
			b_tail = NULL;
		
		if (a_tail != NULL)
		{
			if (a_tail->val > max_val)
			{
				max_val = a_tail->val;
				max_part = 1;
				
			}
		}
		if (b_head != NULL)
		{
			if (b_head->val > max_val)
			{
				max_val = b_head->val;
				max_part = 2;
			}
		}
		if (b_tail != NULL)
		{
			if (b_tail->val > max_val)
			{
				max_val = b_tail->val;
				max_part = 3;
			}
		}
		if (max_part == 1)
		{
			rra(stack);
			p_a = max_val;
			a_tail = stack->a_tail;
		}
		else if (max_part == 2)
		{
			pa(stack);
			p_bh = max_val;
			b_head = stack->b_head;
		}
		else if (max_part == 3)
		{
			rrb(stack);
			pa(stack);
			p_bt = max_val;
			b_tail = stack->b_tail;
		}
		else
		{
			return (1);
		}
	}
	return (0);	
}
int	main(int argc, char *argv[])
{
	t_stack	stack;

	ft_memset(&stack, 0, sizeof(t_stack));
	if (argc == 1)
		return (0);
	if (parsing(argc, argv, &stack) == 1)
		return (print_error_ret1());

	int remain;
	while (1)
	{
		if (stack.a_head == stack.a_tail)
			break ;
		remain = stack.size;
		if (do_lis(&stack) != 0)
			break ;
	}
	while (stack.b_head != NULL)
		do_merge(&stack);
}
