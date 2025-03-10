/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:44 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 04:53:18 by beldemir         ###   ########.fr       */
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
			b->ra += pos;
		else
			b->rra += i->len_b - pos;
		b = b->next;
	}
}

static void calc_of_rr_rrr(t_info *i)
{
	t_stack	*b;

	b = i->st_b;
	while (b)
	{
		while (b->ra > 0 && b->rb > 0)
			(b->rr++, b->ra--, b->rb--);
		while (b->rra > 0 && b->rrb > 0)
			(b->rrr++, b->rra--, b->rrb--);
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
			b->rb += pos;
		else
			b->rrb += i->len_a - pos;
		b = b->next;
	}
	calc_of_rr_rrr(i);
	b = i->st_b;
	while (b)
	{
		b->cost = b->ra + b->rb  + b->rra + b->rrb + b->rr + b->rrr;
		b = b->next;
	}
}

static void	find_cheapest_b(t_info *i)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(i->st_b);
	i->ra = cheapest->ra;
	i->rb = cheapest->rb;
	i->rra = cheapest->rra;
	i->rrb = cheapest->rrb;
	i->rr = cheapest->rr;
	i->rrr = cheapest->rrr;
	reset_costs(i);
}

void	calc_cost_b(t_info *i)
{
	calc_to_bring_top(i);
	calc_to_put_on_a(i);
	find_cheapest_b(i);
}
