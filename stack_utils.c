/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 07:35:37 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/09 22:20:41 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

t_stack	*head_of_stack(t_stack *stack)
{
	while (stack && stack->prev)
		stack = stack->prev;
	return (stack);
}

int	check_stack_sorted(t_stack *stack)
{
	t_stack	*st;

	st = head_of_stack(stack);
	if (!st)
		return (1);
	while (st->next)
	{
		if (st->num > st->next->num)
			return (-1);
		st = st->next;
	}
	return (1);
}

int	check_stack_circular_sorted(t_stack *stack)
{
	t_stack	*start;
	t_stack	*head;
	int		tmp;
	int		num;

	if (!stack || !stack->next)
		return (1);
	start = find_smallest_on_stack(stack);
	tmp = start->num;
	head = stack;
	while (start->next != NULL)
	{
		if (start->num != start->next->num - 1)
			return (-1);
		start = start->next;
	}
	num = start->num;
	while (head->num != tmp)
	{
		if (head->num != ++num)
			return (-1);
		head = head->next;
	}
	return (1);
}

int	pos_on_stack(t_stack *stack, int number)
{
	int		pos;
	t_stack	*ptr;

	ptr = head_of_stack(stack);
	pos = 0;
	while (ptr->next != NULL)
	{
		if (ptr->num == number)
			break ;
		ptr = ptr->next;
		pos++;
	}
	return (pos);
}
