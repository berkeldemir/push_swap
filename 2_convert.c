/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_convert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 08:46:49 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 04:45:05 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	create_st_a(t_info *info)
{
	t_stack	*old;
	t_stack	*new;
	int	i;

	i = 0;
	old = info->st_a;;
	while (++i < info->len_a)
	{
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			quit(info, '-');
		old->next = new;
		new->prev = old;
		new->num = info->tab_a[i];
		new->cost = 0;
		new->ra = 0;
		new->rb = 0;
		new->rra = 0;
		new->rrb = 0;
		new->rr = 0;
		new->rrr = 0;
		new->next = NULL;
		old = new;
	}
}

void	convert_st_a(t_info *info)
{
	info->st_a = (t_stack *)malloc(sizeof(t_stack));
	if (!info->st_a)
		quit(info, '-');
	info->st_a->prev = NULL;
	info->st_a->num = info->tab_a[0];
	info->st_a->next = NULL;
	create_st_a(info);
	free(info->tab_a);
}
