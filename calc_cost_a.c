/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:04 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 19:00:30 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_top(t_info *i)
{
	t_stack	*ptr;

	ptr = i->st_a;
	while (ptr)
	{
		if ((pos_on_stack(i->st_a, ptr->num) < (i->len_a / 2)) || \
		(pos_on_stack(i->st_a, ptr->num) == (i->len_a / 2) && \
		i->len_a % 2 == 1))
			ptr->cost += pos_on_stack(i->st_a, ptr->num);
		else
			ptr->cost += i->len_a - pos_on_stack(i->st_a, ptr->num);
		ptr = ptr->next;
	}
}

static void	calc_to_put_on_b(t_info *i)
{
	t_stack	*a;
	int	index;

	a = i->st_a;
	while (a)
	{	
		index = find_max_below(i->st_b, a->num);
		if (index < (i->len_b / 2) || \
		(index == i->len_b / 2 && i->len_b % 2 == 1))
			a->cost += index;
		else
			a->cost += i->len_b - index;
		a = a->next;
	}
}

static void	find_cheapest_a(t_info *i)
{
	int		index_b;
	int		count;
	t_stack	*cheapest;

	cheapest = find_cheapest(i->st_a);
	reset_costs(i);
	count = pos_on_stack(i->st_a, cheapest->num);
	if (count < (i->len_a / 2) || \
	(count == (i->len_a / 2) && i->len_a % 1 == 1))
		i->rra = i->len_a - count;
	else
		i->ra = count;
	index_b = find_max_below(i->st_b, cheapest->num);
	if (index_b < (i->len_b / 2) || \
	(index_b == i->len_b / 2 && i->len_b % 2 == 1))
		i->rb = index_b;	
	else
		i->rrb = i->len_b - index_b;
}

void	calc_cost_a(t_info *i)
{
	calc_to_bring_top(i);
	calc_to_put_on_b(i);
	find_cheapest_a(i);
}
