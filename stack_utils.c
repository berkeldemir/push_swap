/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:35:37 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 10:13:37 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*find_smallest_on_stack(t_stack *stack)
{
	t_stack	*found;

	while (stack->prev != NULL)
		stack = stack->prev;
	found = stack;
	while (stack->next != NULL)
	{
		if (stack->num < found->num)
			found = stack;
		stack = stack->next;
	}
	return (found);
}

int	check_stack_circular_sorted(t_stack *stack)
{
	int		tmp;

	stack = find_smallest_on_stack(stack);
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (-1);
		stack = stack->next;
	}
	tmp = stack->num;
	while (stack->prev != NULL)
		stack = stack->prev;
	if (tmp > stack->num)
		return (-1);
	while (stack->next != smallest)
	{
		if (stack->num > stack->next->num)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	check_stack_sorted(t_stack *stack)
{
	while (stack->prev != NULL)
		stack = stack->prev;
	while (stack->next != NULL)
	{
		if (stack->num > stack->next->num)
			return (-1);
		stack = stack->next;
	}
	return (1);
}

int	choosen_index_from_stack(t_stack *stack, int index)
{
	int	i;

	while (stack->prev != NULL)
		stack = stack->prev;
	i = -1;
	while (stack->next != NULL && ++i < index)
		stack = stack->next;
	return (stack->num);
}

int	find_stack_size(t_stack *stack)
{
	int	i;

	while (stack->prev != NULL)
		stack = stack->prev;
	i = -1;
	while (stack->next != NULL && ++i >= 0)
		stack = stack->next;
	return (i);
}
