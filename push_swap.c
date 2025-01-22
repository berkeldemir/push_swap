/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/22 09:30:28 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (-1);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] <= '9' || str[i] >= '0' || str[i] == ' ')
			i++;
		else
			return (-1);
	}
	return (i);
}

int	sort_index(int **arr)
{
	t_stack	*a;

	
}

int main(int ac, char *av)
{
	int *a;
	int *b;
	int i;
	int j;

	if (ac < 2)
		return (write(1, "Error\n", 6), -1);
	i = 0;
	while (av[++i])
		if (checker(av[i]) == -1)
			return (write(1, "Error\n", 6), -1);
	a = (int *)malloc(sizeof(int) * i);
	i = 0;
	while (av[++i])
		a[i] = ft_atoi(av[i]);
	// üstteki while düzenlenecek ARG="4 1 6 9" gibi verilebilmeli.
	if (diffchecker(a) == -1)
		return (free(a), free(b), -1);
	sorter(&a);
	free(a);
	free(b);
	return (0);
}
