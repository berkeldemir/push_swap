/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 18:36:44 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 22:20:25 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_top(t_info *i)
{
	t_stack	*ptr;

	ptr = i->st_b;
	while (ptr)
	{
		if (pos_on_stack(i->st_b, ptr->num) <= (i->len_b / 2))
			ptr->cost += pos_on_stack(i->st_b, ptr->num);
		else
			ptr->cost += i->len_b - pos_on_stack(i->st_b, ptr->num);
		ptr = ptr->next;
	}
}

static void	calc_to_put_on_a(t_info *i)
{
	t_stack	*b;
	int		index;

	b = i->st_b;
	while (b)
	{
		index = find_min_above(i->st_a, b->num);
		if (index <= (i->len_a / 2))
			b->cost += index;
		else
			b->cost += i->len_a - index;
		b = b->next;
	}
}

static void	find_cheapest_b(t_info *i)
{
	int		index_a;
	int		count;
	t_stack	*cheapest;

	cheapest = find_cheapest(i->st_b);
	reset_costs(i);
	count = pos_on_stack(i->st_b, cheapest->num);
	if (count <= (i->len_b / 2))
		i->rb = count;
	else
		i->rrb = i->len_b - count;
	index_a = find_min_above(i->st_a, cheapest->num);
	if (index_a <= (i->len_a / 2))
		i->ra = index_a;
	else
		i->rra = i->len_a - index_a;
}

void	calc_cost_b(t_info *i)
{
	calc_to_bring_top(i);
	calc_to_put_on_a(i);
	find_cheapest_b(i);
}
