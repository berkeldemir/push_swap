/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 13:53:33 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/03 12:12:58 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	check_sorted(t_info *i)
{
	int	j;

	j = 0;
	while (i->tab_a[j])
	{
		if (i->tab_a[j + 1])
			if (i->tab_a[j + 1] < i->tab_a[j])
				return (-1);
		else 
			return (1);
		j++;
	}
	return (1);
}

void	sort_4_5()
{
	
}

void    sort(t_info *i)
{
	if (i->len_a == 1)
		return (quit(i, 0), 0);
	if (i->len_a == 2)
		if (i->tab_a[0] == 1)
			return (swap(&i->tab_a));
	if (i->len_a == 3)
	{
		if (i->tab_a[0] == 0 && i->tab[1] == 2)
			(rev_rotate(&i->tab_a), swap(&i->tab_a));
		if (i->tab_a[0] == 2 && i->tab[1] == 1)
			(rotate(&i->tab_a), swap (&i->tab_a));
		if (i->tab_a[0] == 1 && i->tab[1] == 0)
			swap(&i->tab_a);
		if (i->tab_a[0] == 2 && i->tab[1] == 0)
			rotate(&i->tab_a);
		if (i->tab_a[0] == 1 && i->tab_a[1] == 2)
			rev_rotate(&i->tab_a);
	}
	if (i->len_a == 4 || i->len_a == 5)
		sort_4_5(i);
	if (i->len_a > 5 && i->len_a < 100)
		
	check_sorted(i);
}
