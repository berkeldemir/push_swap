/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:31:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 21:41:36 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort_3_numbers(t_info *i)
{	
	int	x;
	int	y;
	int	z;

	x = i->st_a->num;
	y = i->st_a->next->num;
	z = i->st_a->next->next->num;
	if (x > y && y > z)
		(swap_a(i, LOUD), reverse_rotate_a(i, LOUD));
	else if (x > z && z > y)
		(rotate_a(i, LOUD));
	else if (y > x && x > z)
		(reverse_rotate_a(i, LOUD));
	else if (y > z && z > x)
		(reverse_rotate_a(i, LOUD), swap_a(i, LOUD));
	else if (z > x && x > y)
		(swap_a(i, LOUD));
}

static void	sort_4_numbers(t_info *i)
{
	t_stack	*ptr;
	int		index;

	index = 0;
	ptr = i->st_a;
	while (ptr)
	{
		if (ptr->num == find_smallest_on_stack(i->st_a)->num)
			break ;
		ptr = ptr->next;
		index++;
	}
	if (index == 1)
		(rotate_a(i, LOUD));
	else if (index == 2)
		(rotate_a(i, LOUD), rotate_a(i, LOUD));
	else if (index == 3)
		(reverse_rotate_a(i, LOUD));
	push_b(i, LOUD);
	sort_3_numbers(i);
	push_a(i, LOUD);
}

static void	sort_circular_stack(t_info *i)
{
	int		index;
	t_stack	*ptr;

	index = 0;
	ptr = i->st_a;
	while (ptr)
	{
		if (ptr->num == find_smallest_on_stack(i->st_a)->num)
			break ;
		ptr = ptr->next;
		index++;
	}
	if (index < (i->len_a / 2) || \
		(index == i->len_a / 2 && i->len_a % 2 == 1))
		while (index-- > 0)
			rotate_a(i, LOUD);
	else
		while (index++ < i->len_a)
			reverse_rotate_a(i, LOUD);
}

void	sort(t_info *i)
{
	if (check_stack_circular_sorted(i->st_a) == 1)
		sort_circular_stack(i);
	else if (i->len_a == 3)
		sort_3_numbers(i);
	else if (i->len_a == 4)
		sort_4_numbers(i);
	else
		(big_sort(i), sort_circular_stack(i));
}
