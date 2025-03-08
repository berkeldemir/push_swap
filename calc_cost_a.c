/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 13:57:04 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/08 14:44:05 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	pos_found_do_calc(t_stack	*a, int len_b, int	index)
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
	else if (index < ((len_b / 2)) || (index == (len_b / 2) && len_b % 2 == 1))
		constant += index; // ilk yarısındaysa yapmam gereken işlem sayısı
	else
		constant += len_b - index;
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
		prev_val = INT_MAX;
		while (b)
		{
			if ((a->num < prev_val && a->num > b->num) || !b->next)
			{
				pos_found_do_calc(a, i->len_b, pos_on_stack(i->st_b, b->num));
				break ;
			}
			prev_val = b->num;
			b = b->next;
		}
		a = a->next;
	}
}

static void	find_cheapest_a(t_info *i)
{
	int		count;
	t_stack	*cheapest;

	cheapest = find_cheapest(i);
	count = pos_on_stack(i->st_a, cheapest->num);
	if ((i->len_a % 2 == 1 && count > (i->len_a / 2)) || \
	(i->len_a % 2 == 0 && count >= (i->len_a / 2)))
		i->rra = i->len_a - count;
	else
		i->ra = count;
}

static void	calc_rb_rrb(t_info *i)
{
	int		index;
	int		prev_val;
	t_stack	*cheapest;
	t_stack	*b_ptr;

	b_ptr = i->st_b;
	cheapest = find_cheapest(i);
	prev_val = INT_MAX;
	index = 0;
	while (b_ptr)
	{
		if (cheapest->num < prev_val && cheapest->num > b_ptr->num)
			break ;
		prev_val = b_ptr->num;
		b_ptr = b_ptr->next;
		index++;
	}
	if (index == 0)
		return ;
	else if (index == i->len_b)
		i->rrb = 1;
	else if (index < ((i->len_b / 2)) || (index == (i->len_b / 2) && i->len_b % 2 == 1))
		i->rb = index;
	else
		i->rrb = i->len_b - index;
}

void	calc_cost_a(t_info *i)
{
	reset_costs(i);
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
	calc_to_sort_on_b(i);
	find_cheapest_a(i);
	calc_rb_rrb(i);
}
