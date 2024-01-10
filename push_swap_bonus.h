/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:56:02 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/10 14:39:19 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

typedef struct s_node
{
	int				val;
	struct s_node	*pre;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
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


long long	ps_atoll_b(const char *str);
int			add_one_b(char *s, t_node **head, t_node **tail);
int			split_space_b(char *s, t_node **head, t_node **tail);
int			parsing(int argc, char *argv[], t_node **head, t_node **tail);
int			get_oper(t_stack *stack);

#endif