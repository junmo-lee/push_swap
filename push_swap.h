/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:35:35 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/01 22:11:17 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	long	size;
	t_node	*a_head;
	t_node	*a_tail;
	t_node	*b_head;
	t_node	*b_tail;
}	t_stack;

typedef struct s_param
{
	long	*a_pa;
	long	a_size;
	long	*b_pa;
	long	b_size;
	long	ways;
	long	min_idx;
	long	min_val;
	t_node	*cal_temp;
}	t_param;

int			node_pb(t_node **head, t_node **tail, int val);
void		lstclear(t_node **lst);
int			clear_ret(t_stack *stack, long *arr_lis, long *del_dup, int ret);
void		main_init(t_stack *stack, long **arr_lis, long **del_dup, int *ret);

int			sa(t_stack *stack);
int			sb(t_stack *stack);
int			ss(t_stack *stack);

int			pa(t_stack *stack);
int			pb(t_stack *stack);

int			ra(t_stack *stack, int do_print);
int			rb(t_stack *stack, int do_print);
int			rr(t_stack *stack);

int			rra(t_stack *stack, int do_print);
int			rrb(t_stack *stack, int do_print);
int			rrr(t_stack *stack);

long long	ps_atoll(const char *str);
int			parse(int argc, char *argv[], t_stack *stack);

long		*do_lis(t_stack *stack);
int			is_sorted(t_node *start, t_node *end);

long		*stack_to_int_array(t_stack *stack, long size);
long		*del_duplication(t_stack *stack, long *ans);
int			get_lis_len(long *temp);
long		*make_lis(long *arr, long *dp, long *temp, int size);

void		ft_memset_long(long *arr, long val, int len);

int			simple_sort(t_stack *stack);
long		find_min(long *a, long size);
int			sort_5(t_stack *stack, long *a, long max_val);
int			sort_4(t_stack *stack, long *a, long max_val);
int			sort_3(t_stack *stack, long *a);
void		pb_quick_sort(long *data, long start, long end);
void		split_3(t_stack *stack, long *arr_lis, long *arr_stackb);
void		do_best_oper(t_stack *stack, t_param *param);
void		greedy_main(t_stack *stack);
void		do_sorting(t_stack *stack, long *arr_lis, long *arr_stackb);

void		param_init(t_stack *stack, t_param *param);
long		find_close(long b_size, long idx);
long		max_l2(long a, long b);
long		min_l2(long a, long b);
long		abs_l(long a);

long		cal_a_pre_pa(t_stack *stack, t_param *param, long b_val);
long		cal_a_pre_pa_1(t_param *param, t_node *temp, long b_val, long *i);
long		cal_a_pre_pa_2(t_param *param, t_node *temp, long b_val, long *i);
void		final_stage(t_stack *stack);

#endif