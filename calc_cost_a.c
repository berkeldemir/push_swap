/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:04 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:28:09 by beldemir         ###   ########.fr       */
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
}

static void	assign_costs(t_info *i)
{
	t_stack	*ptr;
	int		rr;
	int		rrr;

	ptr = i->st_a;
	while (ptr)
	{
		rr = 0;
		rrr = 0;
		while (ptr->ra > 0 && ptr->rb > 0)
			(rr++, ptr->ra--, ptr->rb--);
		while (ptr->rra > 0 && ptr->rrb > 0)
			(rrr++, ptr->rra--, ptr->rrb--);
		ptr->cost = rr + rrr + ptr->ra + ptr->rb + ptr->rra + ptr->rrb;
		ptr = ptr->next;
	}
}

static void	find_cheapest_a(t_info *i)
{
	t_stack	*cheapest;
	int		pos;

	cheapest = find_cheapest(i->st_a);
	pos = pos_on_stack(i->st_a, cheapest->num);
	if (pos <= (i->len_a / 2))
		i->ra = pos;
	else
		i->rra = i->len_a - pos;
	pos = find_max_below(i->st_b, cheapest->num);
	if (pos <= (i->len_b / 2))
		i->rb = pos;
	else
		i->rrb = i->len_b - pos;
}

void	calc_cost_a(t_info *i)
{
	reset_costs(i);
	calc_to_bring_top(i);
	calc_to_put_on_b(i);
	assign_costs(i);
	find_cheapest_a(i);
}
