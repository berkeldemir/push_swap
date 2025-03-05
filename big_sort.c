/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:28:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/05 18:29:04 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static int	calc_max_bits(t_info *i)
{
	int		max_num;
	int		max_bit;

	max_num = find_biggest_on_stack(i->st_a)->num;
	max_bit = 0;
	while ((max_num >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

static void	(*choose_ra_rra(t_info *i, int bit))(t_info *i, int flag)
{
	t_stack	*ptr;
	int		i_ra;
	int		i_rra;

	i_ra = 0;
	i_rra = 0;
	ptr = i->st_a;
	while (ptr)
	{
		if (((ptr->num >> bit) & 1) != 0)
		{
			if (pos_of_number_on_stack(i->st_a, ptr->num) < (i->len_a / 2))
				i_ra++;
			else
				i_rra++;
		}
		ptr = ptr->next;
	}
	//ft_printf("\nra: %i\nrra:%i\n", i_ra, i_rra);
	if (i_ra >= i_rra)
		return (&rotate_a);
	return (&reverse_rotate_a);
}

void	big_sort(t_info *i)
{
	int		max_bit;
	int		iter;
	int		j;
	t_stack	*ptr;
	void	(*funct)(t_info *i, int flag);

	if (i->len_a != i->len_total)
		ft_printf("An error occured.\n");
	max_bit = calc_max_bits(i);
	j = 0;
	while (j < max_bit)
	{
		funct = choose_ra_rra(i, max_bit - j);
		iter = 0;
		ptr = i->st_a;
		while (ptr)
		{
			if (((ptr->num >> j) & 1) != 0)
				funct(i, LOUD);
			else
				push_b(i, LOUD);
			ptr = ptr->next;
			iter++;
		}
		j++;
	}
	push_a(i, LOUD);
}
