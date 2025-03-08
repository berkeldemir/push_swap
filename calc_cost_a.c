/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:04 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/08 18:53:50 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	calc_to_bring_first(t_info *i)
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

static void	pos_found_do_calc(t_info *i, t_stack	*a, int len_b, int	index)
{
	int	constant;

	constant = 0;
	if (index == 0)
		return ; // direkt atınca yerine cuk oturcak
	else if (index == len_b)
	{
		a->cost += 1; // attıktan sonra bi kere ra yeterli olacak demek
		return ;
	}
	if (index < ((len_b / 2)) || (index == (len_b / 2) && len_b % 2 == 1))
	{
		constant += index; // ilk yarısındaysa yapmam gereken işlem sayısı
		i->rb = constant;
	}
	else
	{
		constant += len_b - index; // ikinci yarısındaysa
		i->rrb = constant;
	}
	constant *= 2;
	if (index > (len_b / 2 - 1))
		constant += 1;
	a->cost += constant;
}

static void	calc_to_sort_on_b(t_info *i)
{
	t_stack	*a;
	t_stack *b;
	int		prev_val;

	a = i->st_a;
	while (a)
	{
		b = i->st_b;
		while (b)
		{
			if (b->prev)
				prev_val = b->prev->num;
			else
				prev_val = INT_MAX;
			if ((a->num < prev_val && a->num > b->num) || !b->next)
			{
				pos_found_do_calc(i, a, i->len_b, pos_on_stack(i->st_b, b->num));
				break ;
			}
			b = b->next;
		}
		a = a->next;
	}
}

static void	find_cheapest_a(t_info *i)
{
	int		count;
	t_stack	*cheapest;
	t_stack	*ptr;

	ptr = i->st_a;
	while (ptr)
	{
		if (ptr->cost < cheapest->cost)
			cheapest = ptr;
		ptr = ptr->next;
	}
	count = pos_on_stack(i->st_a, cheapest->num);
	if ((i->len_a % 2 == 1 && count >= (i->len_a / 2)) || \
	(i->len_a % 2 == 0 && count > (i->len_a / 2)))
	{
		count = i->len_a - count;
		i->rra = count;
	}
	else
		i->ra = count;
	ptr = i->st_b;
	
}

void	calc_cost_a(t_info *info)
{
	reset_costs(info);
	calc_to_bring_first(info);
	calc_to_sort_on_b(info);
	find_cheapest_a(info);
}
