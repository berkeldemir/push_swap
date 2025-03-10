/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:57:20 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*find_smallest_on_stack(t_stack *stack)
{
	t_stack	*found;
	t_stack	*st;

	st = head_of_stack(stack);
	found = st;
	while (st != NULL)
	{
		if (st->num < found->num)
			found = st;
		st = st->next;
	}
	return (found);
}

t_stack	*find_biggest_on_stack(t_stack *stack)
{
	t_stack	*found;
	t_stack	*st;

	st = head_of_stack(stack);
	found = st;
	while (st != NULL)
	{
		if (st->num > found->num)
			found = st;
		st = st->next;
	}
	return (found);
}

int	find_max_below(t_stack *stack, int number)
{
	t_stack	*ptr;
	t_stack	*max_below;
	int		pos;
	int		target_pos;

	pos = 0;
	target_pos = -1;
	ptr = head_of_stack(stack);
	max_below = NULL;
	while (ptr)
	{
		if (ptr->num < number)
		{
			if (!max_below || ptr->num > max_below->num)
			{
				max_below = ptr;
				target_pos = pos;
			}
		}
		pos++;
		ptr = ptr->next;
	}
	if (target_pos == -1)
		return (pos_on_stack(stack, find_biggest_on_stack(stack)->num));
	return (target_pos);
}

int	find_min_above(t_stack *stack, int number)
{
	t_stack	*ptr;
	t_stack	*min_above;
	int		pos;
	int		target_pos;

	pos = 0;
	target_pos = -1;
	ptr = head_of_stack(stack);
	min_above = NULL;
	while (ptr)
	{
		if (ptr->num > number)
		{
			if (!min_above || ptr->num < min_above->num)
			{
				min_above = ptr;
				target_pos = pos;
			}
		}
		pos++;
		ptr = ptr->next;
	}
	if (target_pos == -1)
		return (pos_on_stack(stack, find_smallest_on_stack(stack)->num));
	return (target_pos);
}
