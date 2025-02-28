/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:05:27 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/28 15:02:17 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

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

void    quit_error(t_info *i)
{
    ft_printf("Error\n");
    quit(i, 1);
}

void    quit(t_info *i, int code)
{
    if (i->tab_a)
        free(i->tab_a);
    if (i->tab_b)
        free(i->tab_b);
    if (i)
        free(i);
    if (code == 0)
        exit(EXIT_SUCCESS);
    if (code != 0)
        exit(EXIT_FAILURE);
}
