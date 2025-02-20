/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 07:47:52 by beldemir          #+#    #+#             */
/*   Updated: 2025/02/20 06:45:57 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_addnum(int num, int ind, int *bef)
{
	t_stack	new;
	
	
	
	return (new);
}

int	ft_isnum(char *s)
{
	int	i;
	
	i = 0;
	if (s[0] == '-' || s[i] == '+')
		i++;
	while (s[i])
	{
		if (s[i] == '.' || (s[i] <= '9' && s[i] >= '0'))
			i++;
		else
			return (-1);
	}
	return (i);
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
