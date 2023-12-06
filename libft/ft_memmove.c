/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 21:56:11 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/29 20:22:10 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*src_uc = (unsigned char *)src;
	unsigned char		*dst_uc;
	size_t				i;

	dst_uc = (unsigned char *)dst;
	if (dst_uc == src_uc || len == 0)
		return (dst);
	i = 0;
	if (dst_uc < src_uc)
	{
		while (i < len)
		{
			dst_uc[i] = src_uc[i];
			i++;
		}
		return (dst);
	}
	while (i < len)
	{
		dst_uc[len - i - 1] = src_uc[len - i - 1];
		i++;
	}
	return (dst);
}
