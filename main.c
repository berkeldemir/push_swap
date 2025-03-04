/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 10:15:16 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	main(int ac, char **av)
{
	t_info	*i;
	int		j;

	i = (t_info *)malloc(sizeof(t_info));
	if (!i)
		return (0);
	create_tmp_a(ac, av, i);
	reduce_tmp_a(i);
	convert_st_a(i);
	j = 10;
	while (j--)
	{
		ft_printf("%i\n", i->st_a->num);
		if (i->st_a->next == NULL)
			break ;
		i->st_a = i->st_a->next;
	}
	ft_printf("i\na: %i\nb: %i\n", i->len_total, i->len_a, i->len_b);
	quit(i, '+');
	return (0);
}
