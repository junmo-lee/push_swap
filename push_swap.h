/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:35:35 by junmlee           #+#    #+#             */
/*   Updated: 2024/02/27 22:08:38 by junmlee          ###   ########.fr       */
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
	int		size;
	t_node	*a_head;
	t_node	*a_tail;
	t_node	*b_head;
	t_node	*b_tail;
}	t_stack;

enum e_command {
	e_pa = 1,
	e_pb = 2,
	e_ra = 3,
	e_rb = 4,
	e_rra = 5,
	e_rrb = 6
};


int			node_pb(t_node **head, t_node **tail, int val);
void		lstclear(t_node **lst);

int			sa(t_stack *stack);
int			sb(t_stack *stack);
int			ss(t_stack *stack);

int			pa(t_stack *stack);
int			pb(t_stack *stack);

int			ra(t_stack *stack);
int			rb(t_stack *stack);
int			rr(t_stack *stack);

int			rra(t_stack *stack);
int			rrb(t_stack *stack);
int			rrr(t_stack *stack);

long long	ps_atoll(const char *str);
int			parsing(int argc, char *argv[], t_stack *stack);

t_node		*at(t_node *list, int idx);
int			is_sorted(t_node *start, t_node *end, int is_ascending);
int			make_param(int len, t_node *start_node, int pos, int is_ascending);

int			*stack_to_int_array(t_stack *stack);
int			*stack_to_int_array_del_dup(t_stack *stack, int *ans);

int			get_lis_len(int *temp);

int			*make_lis(int *arr, int *dp, int *temp, int size);
int			*make_lcs(int *arr, int *dp, int *temp, int size);
#endif