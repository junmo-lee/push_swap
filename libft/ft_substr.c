/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:45:49 by junmlee           #+#    #+#             */
/*   Updated: 2023/10/29 20:12:12 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
	{
		arr = (char *)malloc(sizeof(char));
		if (arr == NULL)
			return (NULL);
		*arr = '\0';
		return (arr);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (NULL);
	ft_strlcpy(arr, (char *)s + start, len + 1);
	return (arr);
}
