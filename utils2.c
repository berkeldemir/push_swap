/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 18:12:15 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:11:38 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_info(t_info *i)
{
	i->tmp_a = NULL;
	i->tab_a = NULL;
	i->st_a = NULL;
	i->st_b = NULL;
	i->len_a = 0;
	i->len_b = 0;
	i->len_total = 0;
	i->ra = 0;
	i->rra = 0;
	i->rb = 0;
	i->rrb = 0;
}

void	reset_costs(t_info *i)
{
	t_stack	*a;
	t_stack	*b;

	a = i->st_a;
	b = i->st_b;
	while (a)
	{
		a->cost = 0;
		a->ra = 0;
		a->rb = 0;
		a->rra = 0;
		a->rrb = 0;
		a = a->next;
	}
	while (b)
	{
		b->cost = 0;
		b->ra = 0;
		b->rb = 0;
		b->rra = 0;
		b->rrb = 0;
		b = b->next;
	}
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*ptr;

	ptr = stack;
	cheapest = ptr;
	while (ptr)
	{
		if (ptr->cost < cheapest->cost)
			cheapest = ptr;
		ptr = ptr->next;
	}
	return (cheapest);
}
