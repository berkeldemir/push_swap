/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:44 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:39:48 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_top(t_info *i)
{
	t_stack	*b;
	int		pos;

	b = i->st_b;
	while (b)
	{
		pos = pos_on_stack(i->st_b, b->num);
		if (pos <= (i->len_b / 2))
			b->cost += pos;
		else
			b->cost += i->len_b - pos;
		b = b->next;
	}
}

static void	calc_to_put_on_a(t_info *i)
{
	t_stack	*b;
	int		pos;

	b = i->st_b;
	while (b)
	{
		pos = find_min_above(i->st_a, b->num);
		if (pos <= (i->len_a / 2))
			b->cost += pos;
		else
			b->cost += i->len_a - pos;
		b = b->next;
	}
}

static void	assign_costs(t_info *i)
{
	t_stack	*ptr;
	int		rr;
	int		rrr;

	ptr = i->st_b;
	while (ptr)
	{
		rr = 0;
		rrr = 0;
		while (ptr->ra > 0 && ptr->rb > 0)
		{
			rr++;
			ptr->ra--;
			ptr->rb--;
		}
		while (ptr->rra > 0 && ptr->rrb > 0)
		{
			rrr++;
			ptr->rra--;
			ptr->rrb--;
		}
		ptr->cost = rr + rrr + ptr->ra + ptr->rb + ptr->rra + ptr->rrb;
		ptr = ptr->next;
	}
}

static void	find_cheapest_b(t_info *i)
{
	t_stack	*cheapest;
	int		pos;

	cheapest = find_cheapest(i->st_b);
	pos = pos_on_stack(i->st_b, cheapest->num);
	if (pos <= (i->len_b / 2))
		i->rb = pos;
	else
		i->rrb = i->len_b - pos;
	pos = find_min_above(i->st_a, cheapest->num);
	if (pos <= (i->len_a / 2))
		i->ra = pos;
	else
		i->rra = i->len_a - pos;
}

void	calc_cost_b(t_info *i)
{
	reset_costs(i);
	calc_to_bring_top(i);
	calc_to_put_on_a(i);
	assign_costs(i);
	find_cheapest_b(i);
}
