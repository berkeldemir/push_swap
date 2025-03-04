/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:17:15 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 12:46:18 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_a(t_info *i, int flag)
{
	t_stack	*ptr;
	int		tmp;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_a || !i->st_a->next)
		return ;
	ptr = i->st_a->next;
	tmp = i->st_a->num;
	i->st_a->num = i->st_a->next->num;
	i->st_a->next->num = tmp;
	if (flag == LOUD)
		ft_putendl_fd("sa", 1);
}

void	push_a(t_info *i, int flag)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_b)
		return ;
	b_ptr = i->st_b->next;
	a_ptr = i->st_b;
	if (i->st_b->next)
		i->st_b->next->prev = NULL;
	i->st_b->next = i->st_a;
	if (i->st_a)
		i->st_a->prev = i->st_b;
	i->st_b = b_ptr;
	i->st_a = a_ptr;
	i->len_a++;
	i->len_b--;
	if (flag == LOUD)
		ft_putendl_fd("pa", 1);
}

void	rotate_a(t_info *i, int flag)
{
	t_stack	*new_head;
	t_stack	*old_last;
	t_stack	*ptr;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_a || !i->st_a->next)
		return ;
	ptr = i->st_a;
	new_head = i->st_a->next;
	old_last = i->st_a;
	while (old_last->next)
		old_last = old_last->next;
	ptr->prev = old_last;
	ptr->next = NULL;
	new_head->prev = NULL;
	old_last->next = ptr;
	i->st_a = new_head;
	if (flag == LOUD)
		ft_putendl_fd("ra", 1);
}

void	reverse_rotate_a(t_info *i, int flag)
{
	t_stack	*old_start;
	t_stack	*new_last;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_a || !i->st_a->next)
		return ;
	old_start = i->st_a;
	while (i->st_a->next)
		i->st_a = i->st_a->next;
	new_last = i->st_a->prev;
	i->st_a->next = old_start;
	old_start->prev = i->st_a;
	new_last->next = NULL;
	i->st_a = new_last;
	if (flag == LOUD)
		ft_putendl_fd("rra", 1);
}
