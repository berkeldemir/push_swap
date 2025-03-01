/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 12:58:52 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/01 13:50:59 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reduce(t_info *info)
{
	int	i;
	int	j;
	int	new_value;

	info->tab_a = (int *)malloc(sizeof(int) * info->len_a);
	if (!info->tab_a)
		quit(info, 0);
	i = 0;
	while (i < info->len_a)
	{
		j = 0;
		new_value = 0;
		while (j < info->len_a)
			if (info->tmp_a[j++] < info->tmp_a[i])
				new_value++;
		info->tab_a[i] = new_value;
		i++;
	}
	free(info->tmp_a);
}
