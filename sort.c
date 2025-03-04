/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:31:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 15:06:06 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	sort(t_info *i)
{
	if (i->len_a == 1)
		quit (i, '+');
	else if (i->len_a == 2)
		(swap_a(i, LOUD), quit(i, '+'));
	else if (i->len_a == 3)
	{
		if (i->st_a->num == 0 && i->st_a->next->num == 1)
			quit(i, '+');
		else if (i->st_a->num == 0 && i->st_a->next->num == 2)
			(reverse_rotate_a(i, LOUD), swap_a(i, LOUD), quit(i, '+'));
		else if (i->st_a->num == 2 && i->st_a->next->num == 1)
			(rotate_a(i, LOUD), swap_a(i, LOUD), quit(i, '+'));
		else if (i->st_a->num == 1 && i->st_a->next->num == 0)
			(swap_a(i, LOUD), quit(i, '+'));
		else if (i->st_a->num == 2 && i->st_a->next->num == 0)
			(rotate_a(i, LOUD), quit(i, '+'));
		else
			(reverse_rotate_a(i, LOUD), quit(i, '+'));
	}
	else
		(ft_printf("no\n"), /*big_sort(i),*/ quit(i, '+'));
}
