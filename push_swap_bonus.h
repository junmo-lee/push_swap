/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:56:02 by junmlee           #+#    #+#             */
/*   Updated: 2024/06/02 15:02:19 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "gnl/get_next_line_bonus.h"

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

int			sa_b(t_stack *stack);
int			sb_b(t_stack *stack);
int			ss_b(t_stack *stack);

int			pa_b(t_stack *stack);
int			pb_b(t_stack *stack);

int			ra_b(t_stack *stack);
int			rb_b(t_stack *stack);
int			rr_b(t_stack *stack);

int			rra_b(t_stack *stack);
int			rrb_b(t_stack *stack);
int			rrr_b(t_stack *stack);

long long	ps_atoll(const char *str, int *not_num);
int			add_one(char *s, t_node **head, t_node **tail);
int			split_space_b(char *s, t_stack *stack);
int			parse(int argc, char *argv[], t_stack *stack);
int			get_oper(t_stack *stack, char *input);
int			is_sorted(t_node *start, t_node *end);
#endif