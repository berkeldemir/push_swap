/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/25 19:55:42 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int main(int ac, char **av)
{
	t_info	*i;

	i = (t_info *)malloc(sizeof(t_info));
	if (!i)
		return (0);
	create(ac, av, i);

	int j = -1;
	while (++j < i->len_a)
		ft_printf("%i\n", i->tab_a[j]);
	free(i->tab_a);
	free(i->tab_b);
	free(i);
	return (0);
}
