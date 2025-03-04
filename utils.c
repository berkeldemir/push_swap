/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:05:27 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 10:12:50 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

void	init_info(t_info *i)
{
	i->tmp_a = NULL;
	i->tab_a = NULL;
	i->st_a = NULL;
	i->st_b = NULL;
	i->len_a = 0;
	i->len_b = 0;
	i->len_total = 0;
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

	while (stack && stack->prev)
		stack = stack->prev;
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
	if (i)
		free(i);
	if (code == '+')
		exit(EXIT_SUCCESS);
	if (code == 'e')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	if (code == '-')
		exit(EXIT_FAILURE);
}
