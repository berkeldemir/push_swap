/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:05:27 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/10 07:58:43 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"
#include <limits.h>

void	init_info(t_info *i)
{
	i->tmp_a = NULL;
	i->tab_a = NULL;
	i->st_a = NULL;
	i->st_b = NULL;
	i->len_a = 0;
	i->len_b = 0;
	i->len_total = 0;
	i->ra = 0;
	i->rra = 0;
	i->rb = 0;
	i->rrb = 0;
}

int	check_double(int *tab, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (tab[i] == tab[j])
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

char	*is_empty(char *s)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (free(s), NULL);
	while (s[i])
	{
		if (s[i] <= '9' && s[i] >= '0')
			return (s);
		i++;
	}
	if (s[i] == '\0')
		return (free(s), NULL);
	return (s);
}

static void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = head_of_stack(stack);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

void	quit(t_info *i, char code)
{
	if (i->st_a)
		free_stack(i->st_a);
	if (i->st_b)
		free_stack(i->st_b);
	if (i)
		free(i);
	if (code == '+')
		exit(EXIT_SUCCESS);
	if (code == '-')
		exit(EXIT_FAILURE);
	if (code == 'e')
	{
		ft_putendl_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
}
