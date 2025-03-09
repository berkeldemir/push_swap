/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:28:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 19:04:28 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static void	send_to_b(t_info *i)
{
	while (i->len_a > 3)
	{
		calc_cost_a(i);
		//ft_printf("\nTABLE:\tra:%i\trra:%i\trb:%i\trrb:%i\n", i->ra, i->rra, i->rb, i->rrb);
		while (i->ra > 0 && i->rb > 0)
			(rotate_both(i, LOUD), i->ra--, i->rb--);
		while (i->rra > 0 && i->rrb > 0)
			(reverse_rotate_both(i, LOUD), i->rra--, i->rrb--);
		while (i->ra > 0)
			(rotate_a(i, LOUD), i->ra--);
		while (i->rra > 0)
			(reverse_rotate_a(i, LOUD), i->rra--);
		while (i->rb > 0)
			(rotate_b(i, LOUD), i->rb--);
		while (i->rrb > 0)
			(reverse_rotate_b(i, LOUD), i->rrb--);
		push_b(i, LOUD);
	}
}

static void	get_back_to_a(t_info *i)
{
	while (i->len_b != 0)
	{
		calc_cost_b(i);
		//ft_printf("\nTABLE:\tra:%i\trra:%i\trb:%i\trrb:%i\n", i->ra, i->rra, i->rb, i->rrb);
		while (i->ra > 0 && i->rb > 0)
			(rotate_both(i, LOUD), i->ra--, i->rb--);
		while (i->rra > 0 && i->rrb > 0)
			(reverse_rotate_both(i, LOUD), i->rra--, i->rrb--);
		while (i->ra > 0)
			(rotate_a(i, LOUD), i->ra--);
		while (i->rra > 0)
			(reverse_rotate_a(i, LOUD), i->rra--);
		while (i->rb > 0)
			(rotate_b(i, LOUD), i->rb--);
		while (i->rrb > 0)
			(reverse_rotate_b(i, LOUD), i->rrb--);
		push_a(i, LOUD);
	}
}

void	big_sort(t_info *i)
{
	push_b(i, LOUD);
	push_b(i, LOUD);
	if (check_stack_sorted(i->st_b) == 1)
		swap_b(i, LOUD);
	send_to_b(i);
	sort_3_numbers(i);
	get_back_to_a(i);
}
