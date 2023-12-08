/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 07:05:38 by junmlee           #+#    #+#             */
/*   Updated: 2023/12/08 22:13:46 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*add;

	add = (t_list *)malloc(sizeof(t_list));
	if (add == NULL)
		return (NULL);
	add->next = NULL;
	add->content = content;
	return (add);
}
