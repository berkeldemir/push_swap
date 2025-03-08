/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 15:54:17 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/08 19:52:51 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

int	check_stack_reverse_sorted(t_stack *stack)
{
	t_stack	*st;

	st = head_of_stack(stack);
	if (!st)
		return (1);
	while (st->next)
	{
		if (st->num < st->next->num)
			return (-1);
		st = st->next;
	}
	return (1);
}