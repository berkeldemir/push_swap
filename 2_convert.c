/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:46:49 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 21:56:43 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	convert_st_a(t_info *info)
{
	t_stack	*old;
	t_stack	*new;
	int		i;

	info->st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!info->st_a)
		quit(info, '-');
	info->st_a->prev = NULL;
	info->st_a->num = info->tab_a[0];
	info->st_a->next = NULL;
	old = info->st_a;
	i = 0;
	while (++i < info->len_a)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			quit(info, '-');
		old->next = new;
		new->prev = old;
		new->num = info->tab_a[i];
		new->cost = 0;
		new->next = NULL;
		old = new;
	}
	free(info->tab_a);
}
