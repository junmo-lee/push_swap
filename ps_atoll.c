/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:54:55 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:22:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ps_atoll(const char *str)
{
	long long	ret;
	int			sign;

	sign = 1;
	ret = 0;
	while (*str != '\0' && *str == ' ')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str != ' ')
	{
		if (*str < '0' || *str > '9')
			sign = 0;
		ret *= 10;
		ret += *str - '0';
		str++;
	}
	return (sign * ret);
}
