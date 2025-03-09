/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:44 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 02:00:26 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_top(t_info *i)
{
	t_stack	*ptr;
	int		pos;

	ptr = i->st_b;
	while (ptr)
	{
		pos = pos_on_stack(i->st_b, ptr->num);
		if (pos <= (i->len_b / 2))
			ptr->cost += pos;
		else
			ptr->cost += i->len_b - pos;
		ptr = ptr->next;
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
	int		pos;
	t_stack	*cheapest;

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
