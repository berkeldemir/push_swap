/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:39:24 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/05 21:44:14 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_both(t_info *i, int flag)
{
	swap_a(i, SILENT);
	swap_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("ss", 1);
	if (i->st_a && check_stack_sorted(i->st_a) == 1 && flag == LOUD && \
		i->len_a == i->len_total)
		quit(i, '+');
}

void	rotate_both(t_info *i, int flag)
{
	rotate_a(i, SILENT);
	rotate_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("rr", 1);
	if (i->st_a && check_stack_sorted(i->st_a) == 1 && flag == LOUD && \
		i->len_a == i->len_total)
		quit(i, '+');
}

void	reverse_rotate_both(t_info *i, int flag)
{
	reverse_rotate_a(i, SILENT);
	reverse_rotate_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("rrr", 1);
	if (i->st_a && check_stack_sorted(i->st_a) == 1 && flag == LOUD && \
		i->len_a == i->len_total)
		quit(i, '+');
}
