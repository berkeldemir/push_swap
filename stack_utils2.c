/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 18:39:54 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	find_max_below(t_stack *stack, int number)
{
	t_stack *ptr;
	t_stack	*max_below;

	ptr = stack;
	max_below = find_biggest_on_stack(stack);
	while (ptr)
	{
		if (ptr->num < number && (max_below == find_biggest_on_stack(stack) \
		|| ptr->num > max_below->num))
			max_below = ptr;
		ptr = ptr->next;
	}
	return (pos_on_stack(stack, max_below->num));
}

int	find_min_above(t_stack *stack, int number)
{
	t_stack *ptr;
	t_stack	*min_above;

	ptr = stack;
	min_above = find_smallest_on_stack(stack);
	while (ptr)
	{
		if (ptr->num > number && (min_above == find_smallest_on_stack(stack) \
		|| ptr->num < min_above->num))
			min_above = ptr;
		ptr = ptr->next;
	}
	return (pos_on_stack(stack, min_above->num));
}

t_stack	*find_biggest_on_stack(t_stack *stack)
{
	t_stack	*found;
	t_stack	*st;

	st = stack;
	while (st->prev != NULL)
		st = st->prev;
	found = st;
	while (st != NULL)
	{
		if (st->num > found->num)
			found = st;
		st = st->next;
	}
	return (found);
}

int	number_on_the_index(t_stack *stack, int index)
{
	t_stack	*ptr;

	ptr = stack;
	while (index--)
	{
		if (!ptr)
			return (-1);
		ptr = ptr->next;
	}
	return (ptr->num);
}
