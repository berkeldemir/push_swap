/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:04 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 04:59:22 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_top(t_info *i)
{
	t_stack	*a;
	int		pos;

	a = i->st_a;
	while (a)
	{
		pos = pos_on_stack(i->st_a, a->num);
		if (pos <= (i->len_a / 2))
			a->ra += pos;
		else
			a->rra += i->len_a - pos;
		a = a->next;
	}
}

static void calc_of_rr_rrr(t_info *i)
{
	t_stack	*a;

	a = i->st_a;
	while (a)
	{
		while (a->ra > 0 && a->rb > 0)
			(a->rr++, a->ra--, a->rb--);
		while (a->rra > 0 && a->rrb > 0)
			(a->rrr++, a->rra--, a->rrb--);
		a = a->next;
	}
}

static void	calc_to_put_on_b(t_info *i)
{
	t_stack	*a;
	int		pos;

	a = i->st_a;
	while (a)
	{	
		pos = find_max_below(i->st_b, a->num);
		if (pos <= (i->len_b / 2))
			a->rb += pos;
		else
			a->rrb += i->len_b - pos;
		a = a->next;
	}
	calc_of_rr_rrr(i);
	a = i->st_a;
	while (a)
	{
		a->cost = a->ra + a->rb  + a->rra + a->rrb + a->rr + a->rrr;
		a = a->next;
	}
}


static void	find_cheapest_a(t_info *i)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(i->st_a);
	i->ra = cheapest->ra;
	i->rb = cheapest->rb;
	i->rra = cheapest->rra;
	i->rrb = cheapest->rrb;
	i->rr = cheapest->rr;
	i->rrr = cheapest->rrr;
	reset_costs(i);
}

void	calc_cost_a(t_info *i)
{
	calc_to_bring_top(i);
	calc_to_put_on_b(i);
	find_cheapest_a(i);
}
