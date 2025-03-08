/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:12:15 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/08 14:23:00 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	reset_costs(t_info *i)
{
	t_stack	*a;
	t_stack	*b;

	a = i->st_a;
	b = i->st_b;
	while (a)
	{
		a->cost = 0;
		a = a->next;
	}
	while (b)
	{
		b->cost = 0;
		b = b->next;
	}
	i->ra = 0;
	i->rra = 0;
	i->rb = 0;
	i->rrb = 0;
}

t_stack	*find_cheapest(t_info *i)
{
	t_stack	*cheapest;
	t_stack	*ptr;

	ptr = i->st_a;
	cheapest = ptr;
	while (ptr)
	{
		if (ptr->cost < cheapest->cost)
			cheapest = ptr;
		ptr = ptr->next;
	}
	return (cheapest);
}
