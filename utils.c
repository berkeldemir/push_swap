/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:47:52 by beldemir          #+#    #+#             */
/*   Updated: 2025/01/14 07:57:51 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_addnum(int num, int ind, int *bef)
{
	t_stack	new;
	
	
	
	return (new);
}

int	check_int(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if (str[i] <= '9' && str[i] >= '0')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		i;
	long	num;
	int		isneg;

	i = 0;
	num = 0;
	isneg = 1;
	if (str[i] != '\0' && str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		num = (num * 10) + (str[i] - 48);
		i++;
	}
	return (num * isneg);
}
