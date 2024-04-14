/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:24:18 by junmlee           #+#    #+#             */
/*   Updated: 2024/04/14 17:22:55 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	lower_bound(long *arr, int size, long target)
{
	long	left;
	long	mid;
	long	right;

	left = 0;
	right = size - 1;
	while (left < right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < target)
			left = mid + 1;
		else
			right = mid;
	}
	return (left);
}

//dp는 memset으로 0으로 초기화, temp는 0번째 인덱스가 음수
void	fill_dp(long *arr, long *dp, long *temp, int size)
{
	long	temp_size;
	int		i;

	temp_size = 0;
	i = 0;
	while (i < size)
	{
		dp[i] = lower_bound(temp, temp_size + 1, arr[i]);
		if (temp[dp[i]] == LONG_MIN)
			temp[temp_size++] = arr[i];
		else if (arr[i] < temp[dp[i]])
			temp[dp[i]] = arr[i];
		i++;
	}
}

//temp의 길이 == LIS 길이
int	get_lis_len(long *temp)
{
	int	lis_len;

	lis_len = 0;
	while (*(temp++) != LONG_MIN)
		lis_len++;
	return (lis_len);
}

void	make_lis_fill_ret(long *arr, long *dp, long *ret, long find_idx)
{
	long	i;

	i = find_idx;
	while (i >= 0)
	{
		if (arr[i] < arr[find_idx] && dp[i] + 1 == dp[find_idx])
		{
			find_idx = i;
			*(--ret) = arr[i];
		}
		i--;
	}
}

// 최종적으로 만드는 함수
// arr, dp, temp는 알아서 만들어서 념겨줘야함
long	*make_lis(long *arr, long *dp, long *temp, int size)
{
	long	*ret;
	long	lis_len;
	long	find_idx;

	fill_dp(arr, dp, temp, size);
	lis_len = get_lis_len(temp);
	ret = (long *)malloc((lis_len + 2) * sizeof(long));
	if (ret == NULL)
		return (NULL);
	find_idx = 0;
	while ((dp[find_idx] + 1) != lis_len)
		find_idx++;
	*(ret + lis_len) = LONG_MIN;
	*(ret + lis_len - 1) = arr[find_idx];
	make_lis_fill_ret(arr, dp, ret + lis_len - 1, find_idx);
	return (ret);
}
