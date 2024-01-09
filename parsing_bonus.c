/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:45:57 by junmlee           #+#    #+#             */
/*   Updated: 2023/12/08 22:34:57 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	*make_array(int *cnt, t_parsing *lst)
{
	int	*ret;
	int	i;

	i = 0;
	ret = (int *)malloc((*cnt) * sizeof(int));
	if (lst != NULL)
	{
		while (lst->next != NULL)
		{
			ret[i++] = lst->val;
			lst = lst->next;
		}
	}
	return (ret);
}

int	pb(char *start, t_parsing **lst, t_parsing **head)
{
	t_parsing	*new;

	new = (t_parsing *)malloc(sizeof(t_parsing));
	if (new == NULL)
		return (1);
	new->next = NULL;
	new->val = atoi(start);
	ps_push_back(lst, new, head);
	return (0);
}

int	one(char *s, int *cnt, t_parsing **lst, t_parsing **head)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == ' ')
			i++;
		else
		{
			(*cnt)++;
			if (pb(s + i, lst, head) == 1)
				return (1);
			while (s[i] != '\0' && s[i] != ' ')
				i++;
		}
	}
	return (0);
}

int	*parsing(int argc, char *argv[], int *cnt)
{	
	t_parsing	*lst;
	t_parsing	*head;
	int			idx;

	idx = 1;
	*cnt = 0;
	lst = NULL;
	head = NULL;
	while (idx < argc)
	{
		if (one(argv[idx], cnt, &lst, &head) == 1)
			return (ps_lstclear_null(&lst));
		idx++;
	}
	return (make_array(cnt, lst));
}
