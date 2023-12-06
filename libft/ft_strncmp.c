/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:21:03 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/29 20:26:42 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_uc;
	unsigned char	*s2_uc;

	s1_uc = (unsigned char *)s1;
	s2_uc = (unsigned char *)s2;
	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (*s1_uc != *s2_uc || *s1_uc == 0 || *s2_uc == 0)
			return (*s1_uc - *s2_uc);
		s1_uc++;
		s2_uc++;
		i++;
	}
	return (0);
}
