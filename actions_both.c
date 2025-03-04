/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_both.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 11:39:24 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 12:47:12 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	swap_both(t_info *i, int flag)
{
	swap_a(i, SILENT);
	swap_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("ss", 1);
}

void	rotate_both(t_info *i, int flag)
{
	rotate_a(i, SILENT);
	rotate_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("rr", 1);
}

void	reverse_rotate_both(t_info *i, int flag)
{
	reverse_rotate_a(i, SILENT);
	reverse_rotate_b(i, SILENT);
	if (flag == LOUD)
		ft_putendl_fd("rrr", 1);
}
