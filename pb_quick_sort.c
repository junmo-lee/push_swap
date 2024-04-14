/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb_quick_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 18:43:47 by junmlee           #+#    #+#             */
/*   Updated: 2024/03/11 18:54:59 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	long_swap(long *a, long *b)
{
	long	temp;

	temp = *b;
	*b = *a;
	*a = temp;
}

void	pb_quick_sort(long *data, long start, long end)
{
	long	i;
	long	j;

	if (start >= end)
		return ;
	i = start + 1;
	j = end;
	while (i <= j)
	{
		while (i <= end && data[i] <= data[start])
			i++;
		while (j > start && data[j] >= data[start])
			j--;
		if (i > j)
			long_swap(data + j, data + start);
		else
			long_swap(data + i, data + j);
	}
	pb_quick_sort(data, start, j - 1);
	pb_quick_sort(data, j + 1, end);
}
