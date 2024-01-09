/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:56:02 by junmlee           #+#    #+#             */
/*   Updated: 2024/01/09 16:34:08 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "gnl_bonus/get_next_line_bonus.h"

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

int			pb_b(t_node **head, t_node **tail, int val);
void		lstclear_b(t_node **lst);

long long	ps_atoll_b(const char *str);
int			add_one_b(char *s, t_node **head, t_node **tail);
int			split_space_b(char *s, t_node **head, t_node **tail);
int			parsing(int argc, char *argv[], t_node **head, t_node **tail);


#endif