/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:07:35 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/29 20:17:05 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*arr;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	arr = malloc(count * size);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, count * size);
	return (arr);
}
