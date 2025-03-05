/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:28:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/05 22:47:35 by beldemir         ###   ########.fr       */
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

static void (*choose_ra_rra(t_info *info, int bit))(t_info *info, int flag)
{
    t_stack *ptr_head;
	t_stack	*ptr_last;
    int index;

    index = 0;
    ptr_head = head_of_stack(info->st_a)->next;
	ptr_last = ptr_head;
	while (ptr_last->next)
		ptr_last = ptr_last->next;
    while (ptr_head->next && ptr_last->prev)
	{
		if (((ptr_last->num >> bit) & 1) == 0)
			return (&reverse_rotate_b);
		else if (((ptr_head->num >> bit) & 1) == 0)
			return (&rotate_a);
		ptr_head = ptr_head->next;
		ptr_last = ptr_last->prev;
	}
	return (&rotate_a);
}

void	big_sort(t_info *info)
{
	int		i;
	int		j;
	int		len;
	t_stack	*ptr;
	void	(*funct)(t_info *i, int flag);

	if (info->len_a != info->len_total)
		ft_printf("An error occured.\n");
	i = 0;
	while (i < calc_max_bits(info))
	{
		j = 0;
		len = info->len_a;
		while (j < len)
		{
			funct = choose_ra_rra(info, i);
			ptr = head_of_stack(info->st_a);
			if (((ptr->num >> i) & 1) == 1)
				funct(info, LOUD);
			else
				push_b(info, LOUD);
			j++;
		}
		while (info->len_b != 0)
			push_a(info, LOUD);
		i++;
	}
}
