/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 08:46:58 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 09:07:36 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

static char	*first(int ac, char **av)
{
	char	*tmp1;
	char	*tmp2;
	int		i;
	int		j;

	i = 1;
	if (ac < 2)
		return (NULL);
	
	tmp2 = ft_strdup(av[i]);
	while (av[i])
	{
		j = -1;
		while (av[i][++j])
			if (!ft_isdigit(av[i][j]) && av[i][j] != ' ' && \
			av[i][j] != '+' && av[i][j] != '-')
				return (free(tmp2), NULL);
		tmp1 = ft_strjoin(tmp2, " ");
		free(tmp2);
		tmp2 = ft_strjoin(tmp1, av[i]);
		free(tmp1);
		i++;
	}
	return (tmp2);
}

t_list  *check(int ac, char **av)
{
    char    *full;
    
    full = first(ac, av);
    if (!full)
        return (NULL);

    free(full);
    return (NULL);
}
