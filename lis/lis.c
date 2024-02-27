/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 02:24:18 by junmlee           #+#    #+#             */
/*   Updated: 2024/02/27 22:10:49 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "../push_swap.h"

int	lower_bound(int *arr, int size, int target)
{
	int	left;
	int	mid;
	int	right;

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
void	fill_dp(int *arr, int *dp, int *temp, int size)
{
	int	temp_size;
	int	i;

	temp_size = 1;
	i = 0;
	while (i < size)
	{
		dp[i] = lower_bound(temp, temp_size + 1, arr[i]);
		if (temp[dp[i]] == 0)
			temp[temp_size++] = arr[i];
		else if (arr[i] < temp[dp[i]])
			temp[dp[i]] = arr[i];
		i++;
	}
}

//temp의 길이 == LIS 길이
int	get_lis_len(int *temp)
{
	int	lis_len;

	lis_len = 0;
	while (*(++temp) != 0)
		lis_len++;
	return (lis_len);
}

// 최종적으로 만드는 함수
// arr, dp, temp는 알아서 만들어서 념겨줘야함
int	*make_lis(int *arr, int *dp, int *temp, int size)
{
	int	*ret;
	int	lis_len;
	int	find_idx;
	int	i;

	fill_dp(arr, dp, temp, size);
	lis_len = get_lis_len(temp);
	ret = (int *)malloc((lis_len + 1) * sizeof(int));
	ft_memset(ret, 0, (lis_len + 1) * sizeof(int));
	if (ret == 0)
		return (0);
	find_idx = 0;
	while (dp[find_idx] != lis_len)
		find_idx++;
	ret += lis_len;
	*(--ret) = arr[find_idx];
	i = find_idx;
	while (--i > 0)
	{
		if (arr[i] < arr[find_idx] && dp[i] + 1 == dp[find_idx])
		{
			find_idx = i;
			*(--ret) = arr[i];
		}
	}
	return (ret);
}

int	upper_bound(int *arr, int size, int target)
{
	int	left;
	int	mid;
	int	right;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] > target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

void	fill_dp_lcs(int *arr, int *dp, int *temp, int size)
{
	int	temp_size;
	int	i;

	temp_size = 1;
	i = 0;
	while (i < size)
	{
		dp[i] = upper_bound(temp, temp_size + 1, arr[i]);
		if (temp[dp[i]] == 0)
			temp[temp_size++] = arr[i];
		else if (arr[i] > temp[dp[i]])
			temp[dp[i]] = arr[i];
		i++;
	}
}

int	*make_lcs(int *arr, int *dp, int *temp, int size)
{
	int	*ret;
	int	lis_len;
	int	find_idx;
	int	i;

	fill_dp_lcs(arr, dp, temp, size);
	lis_len = get_lis_len(temp);
	ret = (int *)malloc((lis_len + 2) * sizeof(int));
	ft_memset(ret, 0, (lis_len + 2) * sizeof(int));
	if (ret == 0)
		return (0);
	find_idx = 0;
	while (dp[find_idx] != lis_len)
		find_idx++;
	ret += lis_len;
	if (*arr == 0 || lis_len == 0)
		return (ret);
	*(ret) = arr[find_idx];
	i = find_idx;
	while (--i > 0)
	{
		if (arr[i] > arr[find_idx] && dp[i] + 1 == dp[find_idx])
		{
			find_idx = i;
			*(--ret) = arr[i];
		}
	}
	return (ret);
}