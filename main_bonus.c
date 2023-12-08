/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmlee <junmlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 15:54:11 by junmlee           #+#    #+#             */
/*   Updated: 2023/12/08 22:24:17 by junmlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	int		*arg;
	int		cnt;

	if (argc < 2)
		return (0);
	arg = parsing(argc, argv, &cnt);
	if (arg == NULL)
		exit(1);
}
