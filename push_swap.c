/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 07:51:09 by beldemir          #+#    #+#             */
/*   Updated: 2024/12/24 12:29:33 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	isarg_int(char *arg)
{
	int	number;

	while ()
}

int main(int ac, char *av)
{
	int *a;
	int *b;
	int i;
	int	c;

	if (ac < 2)
		return (0);
	i = -1;
	while (av[++i])
		if (isarg_int(av[i]) == -1)
			return (write(1, "Error\n", 6), -1);
	a = (int *)malloc(sizeof(int) * i);
	i = -1;
	while (av[++i])
		a[i - 1] = ft_atoi(av[i]);
	
	free(a);
}
