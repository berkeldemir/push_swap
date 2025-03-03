/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_atoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beldemir <beldemir@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:56:42 by beldemir          #+#    #+#             */
/*   Updated: 2025/03/03 12:12:16 by beldemir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./push_swap.h"

int	new_atoi(const char *str, int *tab_num)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] != '\0' && (str[i] == 32 || (str[i] <= 13 && str[i] >= 9)))
		i++;
	if (str[i] != '\0' && (str[i] == '-' || str[i] == '+'))
		if (str[i++] == '-')
			sign *= -1;
	if (str[i - 1])
		if ((str[i - 1] == '-' || str[i - 1] == '+') && str[i] == '0')
			return (-1);
	while (str[i] != '\0' && ft_isdigit(str[i]) == 1)
	{
		num = (num * 10) + (str[i++] - 48);
		if (num * (long)sign > 2147483647 || num * (long)sign < -2147483648)
			return (-1);
	}
	if (!(str[i] == '\0' || str[i] == ' '))
		return (-1);
	*tab_num = num * sign;
	return (1);
}
