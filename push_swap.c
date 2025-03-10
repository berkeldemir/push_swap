/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:56:27 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	t_info	*i;

	i = (t_info *)malloc(sizeof(t_info));
	if (!i)
		return (0);
	create_tmp_a(ac, av, i);
	reduce_tmp_a(i);
	convert_st_a(i);
	if (check_stack_sorted(i->st_a) == -1)
		sort(i);
	else
		quit(i, '+');
	quit(i, '-');
	return (0);
}
