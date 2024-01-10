/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:35:35 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 16:46:17 by junmlee          ###   ########.fr       */
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
void		sort_list(t_node *list_head, t_node *list_tail, int len, int pos);

#endif