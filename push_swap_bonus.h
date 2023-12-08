/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:56:02 by junmlee           #+#    #+#             */
/*   Updated: 2023/12/08 22:04:48 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H

# include "libft/libft.h"
# include "gnl_bonus/get_next_line_bonus.h"

typedef struct s_parsing
{
	int					val;
	struct s_parsing	*next;
}	t_parsing;

void	ps_push_back(t_parsing **lst, t_parsing *new, t_parsing **cache);
void	*ps_lstclear_null(t_parsing **lst);
int	*parsing(int argc, char *argv[], int *cnt);
#endif