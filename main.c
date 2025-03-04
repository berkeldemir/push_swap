/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 17:43:46 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	print_stacks(t_info *i)
{
	t_stack *head = i->st_a;
	ft_printf("A:\t");
	while (head)
	{
		ft_printf("%i\t", head->num);
		head = head->next;
	}
	t_stack *head2 = i->st_b;
	ft_printf("\nB:\t");
	while (head2)
	{
		ft_printf("%i\t", head2->num);
		head2 = head2->next;
	}
	ft_printf("\nt: %i\na: %i\nb: %i\n\n", i->len_total, i->len_a, i->len_b);
}

int	main(int ac, char **av)
{
	t_info	*i;
	i = (t_info *)malloc(sizeof(t_info));
	if (!i)
		return (0);
	create_tmp_a(ac, av, i);
	reduce_tmp_a(i);
	convert_st_a(i);
	//print_stacks(i);
	if (check_stack_sorted(i->st_a) == -1)
		sort(i);
	//print_stacks(i);
	quit(i, '+');
	return (0);
}
