/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:46:58 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/04 14:16:45 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static char	*merge_args(char **av, char **tmp1, char **tmp2)
{
	int	j;
	int	i;

	i = 1;
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			if ((!ft_isdigit(av[i][j]) && av[i][j] != ' ' && \
			av[i][j] != '+' && av[i][j] != '-') || \
			((av[i][j] == '-' || av[i][j] == '+') && \
			(!ft_isdigit(av[i][j + 1]))))
				return (free(*tmp2), NULL);
		*tmp1 = ft_strjoin(*tmp2, " ");
		free(*tmp2);
		if (!*tmp1)
			return (NULL);
		*tmp2 = ft_strjoin(*tmp1, av[i]);
		free(*tmp1);
		if (!*tmp2)
			return (NULL);
		i++;
	}
	return (*tmp2);
}

static char	*parse_args(int ac, char **av)
{
	char	*tmp1;
	char	*tmp2;

	if (ac < 2)
		return (NULL);
	tmp1 = NULL;
	tmp2 = ft_strdup("");
	if (!tmp2)
		return (NULL);
	tmp2 = merge_args(av, &tmp1, &tmp2);
	if (!tmp2)
		return (NULL);
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
		if ((ft_isdigit((int)str[i - 1]) || \
		str[i - 1] == '+' || str[i - 1] == '-') && \
		(str[i] == ' ' || str[i] == '\0'))
			count++;
		if ((str[i - 1] == '+' || str[i - 1] == '-') && \
		(str[i] == ' ' || str[i] == '\0'))
			return (-1);
		i++;
	}
	return (count);
}

static int	*generate_a(char *full, int count)
{
	int	*tmp_a;
	int	start;
	int	i;

	tmp_a = (int *)malloc(sizeof(int) * count);
	if (!tmp_a)
		return (NULL);
	start = 0;
	i = 0;
	while (i < count && full[start] != '\0')
	{
		while (full[start] == ' ' && full[start] != '\0')
			start++;
		if (full[start] == '\0')
			break ;
		if (new_atoi(&full[start], &tmp_a[i]) == -1)
			return (free(tmp_a), NULL);
		i++;
		while (full[start] != ' ' && full[start] != '\0')
			start++;
	}
	if (i != count)
		return (free(tmp_a), NULL);
	return (tmp_a);
}

void	create_tmp_a(int ac, char **av, t_info *i)
{
	char	*full;

	if (ac < 2)
		quit(i, '-');
	init_info(i);
	full = parse_args(ac, av);
	if (full == NULL)
		quit(i, 'e');
	i->len_a = find_count(full);
	if (i->len_a == -1)
		quit(i, 'e');
	i->len_total = i->len_a;
	i->tmp_a = generate_a(full, i->len_a);
	if (i->tmp_a == NULL)
		quit(i, 'e');
	free(full);
	if (check_double(i->tmp_a, i->len_a) == -1)
		(free(i->tmp_a), quit(i, 'e'));
}
