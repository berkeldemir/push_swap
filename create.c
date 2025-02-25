/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:46:58 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/25 20:11:55 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static char	*merge_args(int ac, char **av)
{
	char	*tmp1;
	char	*tmp2;
	int		i;
	int		j;

	i = 1;
	if (ac < 2)
		return (NULL);
	tmp2 = ft_strdup("");
	if (!tmp2)
		return (NULL);	
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
		{
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && \
			av[i][j] != '+' && av[i][j] != '-')
				return (free(tmp2), NULL);
			if ((av[i][j] == '-' || av[i][j] == '+') && \
			(!ft_isdigit(av[i][j + 1])))
				return (free(tmp2), NULL);
		}
		tmp1 = ft_strjoin(tmp2, " ");
		free(tmp2);
		if (!tmp1)
			return (NULL);
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		if (!tmp2)
			return (NULL);
		i++;
	}
	tmp1 = ft_strjoin(tmp2, " ");
	free(tmp2);
	if (!tmp1)
		return (NULL);
	return (is_empty(tmp1));
}

static int	find_count(char *str)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	while (str[i])
	{
		if ((ft_isdigit((int)str[i - 1]) ||\
		str[i - 1] == '+' || str[i - 1] == '-') && \
		(str[i] == ' ' || str[i] == '\0'))
			count++;
		if ((str[i - 1] == '+' || str[i - 1] == '-') && \
		(str[i] == ' ' || str[i] == '\0'))
			return (-1); // + veya -'den sonra sayı yok demek.
		i++;
	}
	return (count);
}

static int	*generate_a(char *full, int count)
{
	int	*tab_a;
	int	start;
	int	i;

	tab_a = (int *)malloc(sizeof(int) * count);
	if (!tab_a)
		return (NULL);
	start = 0;
	i = 0;
	while (i < count && full[start] != '\0')
	{
		while (full[start] == ' ' && full[start] != '\0')
			start++;
		if (full[start] == '\0')
			break;
		tab_a[i++] = ft_atoi(&full[start]);
		while (full[start] != ' ' && full[start] != '\0')
			start++;
	}
	if (i != count)
	{
		free(tab_a);
		return (NULL);
	}
	return (tab_a);
}

void	create(int ac, char **av, t_info *i)
{
	char    *full;

	i->tab_a = NULL;
	i->tab_b = NULL;
	i->len_a = 0;
	i->len_b = 0;
	i->count = 0;
	full = merge_args(ac, av);
	if (full == NULL)
		quit_error(i);
	i->len_a = find_count(full);
	if (i->len_a == -1)
		quit_error(i);
	i->tab_a = generate_a(full, i->len_a);
	if (i->tab_a == NULL)
		quit_error(i);
	free(full);
	if (check_double(i->tab_a, i->len_a) == -1)
		quit_error(i);
}
