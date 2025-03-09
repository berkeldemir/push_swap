/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:44 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 02:04:04 by beldemir         ###   ########.fr       */
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

static void	find_cheapest_b(t_info *i)
{
	t_stack	*cheapest;
	int		pos;

	cheapest = find_cheapest(i->st_b);
	reset_costs(i);
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
	calc_to_bring_top(i);
	calc_to_put_on_a(i);
	find_cheapest_b(i);
}
