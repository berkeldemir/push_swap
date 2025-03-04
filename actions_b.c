/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:34:26 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 12:46:57 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_b(t_info *i, int flag)
{
	t_stack	*ptr;
	int		tmp;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_b || !i->st_b->next)
		return ;
	ptr = i->st_b->next;
	tmp = i->st_b->num;
	i->st_b->num = i->st_b->next->num;
	i->st_b->next->num = tmp;
	if (flag == LOUD)
		ft_putendl_fd("sb", 1);
}

void	push_b(t_info *i, int flag)
{
	t_stack	*a_ptr;
	t_stack	*b_ptr;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_a)
		return ;
	a_ptr = i->st_a->next;
	b_ptr = i->st_a;
	if (i->st_a->next)
		i->st_a->next->prev = NULL;
	i->st_a->next = i->st_b;
	if (i->st_b)
		i->st_b->prev = i->st_a;
	i->st_a = a_ptr;
	i->st_b = b_ptr;
	i->len_a--;
	i->len_b++;
	if (flag == LOUD)
		ft_putendl_fd("pb", 1);
}

void	rotate_b(t_info *i, int flag)
{
	t_stack	*new_head;
	t_stack	*old_last;
	t_stack	*ptr;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_b || !i->st_b->next)
		return ;
	ptr = i->st_b;
	new_head = i->st_b->next;
	old_last = i->st_b;
	while (old_last->next)
		old_last = old_last->next;
	ptr->prev = old_last;
	ptr->next = NULL;
	new_head->prev = NULL;
	old_last->next = ptr;
	i->st_b = new_head;
	if (flag == LOUD)
		ft_putendl_fd("rb", 1);
}

void	reverse_rotate_b(t_info *i, int flag)
{
	t_stack	*old_start;
	t_stack	*new_last;

	i->st_a = head_of_stack(i->st_a);
	i->st_b = head_of_stack(i->st_b);
	if (!i->st_b || !i->st_b->next)
		return ;
	old_start = i->st_b;
	while (i->st_b->next)
		i->st_b = i->st_b->next;
	new_last = i->st_b->prev;
	i->st_b->next = old_start;
	old_start->prev = i->st_b;
	new_last->next = NULL;
	i->st_b = new_last;
	if (flag == LOUD)
		ft_putendl_fd("rrb", 1);
}
