/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/14 07:53:13 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int ac, char *av)
{
	int *a;
	int *b;
	int i;
	int	c;

	if (ac < 2)
		return (write(1, "Error\n", 6), -1);
	i = -1;
	while (av[++i])
		if (check_int(av[i]) == -1)
			return (write(1, "Error\n", 6), -1);
	a = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (av[++i])
		a[i] = ft_atoi(av[i]);
	
	free(a);
	free(b);
}
